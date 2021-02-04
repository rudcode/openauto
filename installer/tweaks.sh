#!/bin/sh

# some usefull things (thanks to oz_paulb from mazda3revolution.com)

get_cmu_sw_version() {
  _ver=$(/bin/grep "^JCI_SW_VER=" /jci/version.ini | /bin/sed 's/^.*_\([^_]*\)\"$/\1/')
  _patch=$(/bin/grep "^JCI_SW_VER_PATCH=" /jci/version.ini | /bin/sed 's/^.*\"\([^\"]*\)\"$/\1/')
  _flavor=$(/bin/grep "^JCI_SW_FLAVOR=" /jci/version.ini | /bin/sed 's/^.*_\([^_]*\)\"$/\1/')

  if [ -n "${_flavor}" ]; then
    echo "${_ver}${_patch}-${_flavor}"
  else
    echo "${_ver}${_patch}"
  fi
}

MYDIR=$(dirname $(readlink -f "$0"))
CMU_SW_VER=$(get_cmu_sw_version)
if [ -f "${MYDIR}/installer_log.txt" ]; then
  #save old logs
  logidx=1
  while [ -f "${MYDIR}/installer_log_${logidx}.txt" ]; do
    logidx=$((logidx + 1))
  done
  mv "${MYDIR}/installer_log.txt" "${MYDIR}/installer_log_${logidx}.txt"
fi

log_message() {
  printf "$*" >>"${MYDIR}/installer_log.txt"
  /bin/fsync "${MYDIR}/installer_log.txt"
}

#============================= DIALOG FUNCTIONS

show_message() { # $1 - title, $2 - message
  killall jci-dialog
  log_message "= POPUP INFO: $*\n"
  /jci/tools/jci-dialog --info --title="$1" --text="$2" --no-cancel
}

show_confirmation() { # $1 - title, $2 - message
  killall jci-dialog
  log_message "= POPUP CONFIRM: $*\n"
  /jci/tools/jci-dialog --confirm --title="$1" --text="$2" --no-cancel
  return $?
}

show_error() { # $1 - title, $2 - message
  killall jci-dialog
  log_message "= POPUP ERROR: $*\n"
  /jci/tools/jci-dialog --error --title="$1" --text="$2" --ok-label='OK' --no-cancel
}

show_question() { # $1 - title, $2 - message, $3 - ok label, $4 - cancel label
  killall jci-dialog
  log_message "= POPUP: $*\n"
  /jci/tools/jci-dialog --question --title="$1" --text="$2" --ok-label="$3" --cancel-label="$4"
  return $?
}

#============================= INSTALLATION HELPERS

check_mount_point() {
  if [ -f "${MYDIR}/installer_log.txt" ]; then
    log_message "OK\n"
  else
    log_message "FAILED!\n"
    show_error "ERROR!" "Mount point not found, have to reboot again."
    sleep 1
    reboot
    exit
  fi
}

disable_watchdog_and_remount() {
  echo 1 >/sys/class/gpio/Watchdog\ Disable/value || {
    log_message "Disabling Watchdog failed"
    return 1
  }
  mount -o rw,remount / || {
    log_message "Remounting root filesystem failed"
    return 1
  }
  return 0
}

install_openauto() {
  log_message "Running Installer... "
  sh "${MYDIR}"/openauto_installer.run --noexec || {
    log_message "Unpacking OpenAuto Failed"
    return 1
  }
  chmod +x /mnt/data_persist/dev/bin/aa_installer || {
    log_message "chmod aa_installer failed "
    return 1
  }
  /mnt/data_persist/dev/bin/aa_installer || {
    log_message "aa_installer failed"
    return 1
  }
  log_message "DONE\n"
  return 0
}

remove_openauto() {
  log_message "Removing OpenAuto\n"
  mv /mnt/data_persist/dev/backup/jci/* /jci/
  rm -rf /jci/gui/apps/_androidauto/
  rm -rf /jci/opera/opera_dir/userjs/additionalApps.js
  rm -rf /jci/opera/opera_dir/userjs/additionalAppsadditionalApps.json
  rm -rf /mnt/data_persist/dev/bin/autoapp
  rm -rf /mnt/data_persist/dev/bin/aa_installer
  rm -rf /mnt/data_persist/dev/bin/headunit_libs
  rm -rf /mnt/data_persist/dev/backup
}

remove_headunit() {
  if killall -q -9 headunit; then
    log_message "headunit KILLED\n"
  else
    log_message "FAILED! No 'headunit' process found or could not kill it.\n"
  fi
  log_message "Reverting opera.ini file ... "
  reverted=0
  # -- Revert /jci/opera/opera_home/opera.ini from backup
  if [ -f /jci/opera/opera_home/opera.ini.org ]; then
    log_message "from backup ... "
    if mv -a /jci/opera/opera_home/opera.ini.org /jci/opera/opera_home/opera.ini; then
      log_message "DONE\n"
      reverted=1
    else
      log_message "FAILED ... trying the same "
    fi
  fi
  if [ ${reverted} -eq 0 ]; then
    log_message "by reverting changes ... "
    sed -i 's/User JavaScript=1/User JavaScript=0/g' /jci/opera/opera_home/opera.ini &&
      sed -i 'Allow File XMLHttpRequest=1/d' /jci/opera/opera_home/opera.ini
    if [ $? -eq 0 ]; then
      log_message "DONE\n"
    else
      log_message "FAILED\n"
    fi
  fi
  #Revert fps since once we try to match original state of JCI
  if [ -f /jci/opera/opera_dir/userjs/fps.js.bak ]; then
    log_message "Reverting fps.js from backup ... "
    if mv /jci/opera/opera_dir/userjs/fps.js.bak /jci/opera/opera_dir/userjs/fps.js; then
      log_message "DONE\n"
    else
      log_message "FAILED\n"
    fi
  fi
  if grep -Fq "# Android Auto start" /jci/scripts/stage_wifi.sh; then
    log_message "Reverting stage_wifi.sh ... "
    reverted=0
    if [ -f "/jci/scripts/stage_wifi.sh.bak" ]; then
      log_message " from backup ... "
      if mv /jci/scripts/stage_wifi.sh.bak /jci/scripts/stage_wifi.sh; then
        log_message "DONE\n"
        reverted=1
      else
        log_message "FAILED ... trying the same "
      fi
    fi
    if [ ${reverted} -eq 0 ]; then
      log_message "by reverting changes ... "
      sed -i '/# Android Auto start/d' /jci/scripts/stage_wifi.sh &&
        sed -i '/headunit-wrapper/d' /jci/scripts/stage_wifi.sh &&
        sed -i '/check-usb.sh/d' /jci/scripts/stage_wifi.sh
      if [ $? -eq 0 ]; then
        log_message "DONE\n"
      else
        log_message "FAILED\n"
      fi
    fi
  fi
  # Remove Android Auto Headunit App
  log_message "Removing AA files ... "
  rm /tmp/mnt/data_persist/dev/bin/headunit || log_message "headunit failed ... "
  rm /tmp/mnt/data_persist/dev/bin/headunit-wrapper || log_message "headunit-wrapper failed ... "
  rm /tmp/mnt/data_persist/dev/bin/headunit.json || log_message "headunit.json failed ... "
  rm /tmp/mnt/data_persist/dev/bin/check-usb.sh || log_message "check-usb.sh failed ... "
  rm -rf /tmp/mnt/data_persist/dev/bin/headunit_libs || log_message "headunit_libs failed ... "
  rm -rf /jci/gui/apps/_androidauto || log_message "_androidauto failed ... "
  rm /jci/opera/opera_dir/userjs/additionalApps.* || "additionalApps.* failed ... "
  log_message "DONE\n"
}

#============================= INSTALLATION STARTS HERE

log_message "Installer started.\n"

log_message "MYDIR = ${MYDIR}\n"
log_message "CMU version = ${CMU_SW_VER}\n"

# check software version first
echo "${CMU_SW_VER}" | /bin/sed "/^5[569]\..*/Q 1"
if [ $? -ne 1 ]; then
  log_message "Script aborted due to CMU version mismatch."
  show_message "Aborted" "This version of CMU is not supported. Please update first."
  exit
fi

# first test, if copy from MZD to sd card is working to test correct mount point
log_message "Check mount point ... "
check_mount_point

# ask if proceed with installation
if ! show_question "AA INSTALL SCRIPT" "Welcome to OpenAuto installation script. Would you like to proceed?" "Proceed" "Abort"; then
  log_message "Installation aborted.\n"
  show_message "Aborted" "Script aborted. Please remove the USB drive. There is no need to reboot."
  exit
fi

# disable watchdog and allow write access
log_message "Disabling watchdog and remounting for write access ... "
if disable_watchdog_and_remount; then
  log_message "SUCCESS\n"
else
  log_message "FAILED\n"
  show_error "ERROR!" "Could not disable watchdog or remount filesystem. Rebooting."
  sleep 1
  reboot
  exit 1
fi

installed=0
remove=0
# check whether we have AA already installed
# check for headunit-wrapper to see if headunit was installed
if [ -f /tmp/mnt/data_persist/dev/bin/headunit-wrapper ]; then
  log_message "YES\n"
  show_question "CHOOSE ACTION" "You have headunit already installed. Would you like to remove it" "REMOVE" "CANCEL"
  remove=$?
  if [ ${remove} -eq 1 ]; then
    log_message "Canceled.\n"
  else
    log_message "Removing Headunit.\n"
    remove_headunit
  fi
else
  log_message "headunit not detected\n"
  log_message "Installing OpenAuto.\n"
fi

log_message "Check whether OpenAuto is installed ... "
if smctl -g | grep autoapp; then
  installed=1
  log_message "YES\n"
  show_question "CHOOSE ACTION" "You have OpenAuto already installed. Would you like to update or remove it?" "UPDATE" "REMOVE"
  remove=$?
  if [ ${remove} -eq 1 ]; then
    log_message "Removing OpenAuto.\n"
  else
    log_message "Updating OpenAuto.\n"
  fi
  log_message "Stopping AutoApp ... "
  smctl -n autoapp -s -w
else
  log_message "NO\n"
  log_message "Installing OpenAuto.\n"
fi

if [ ${installed} -eq 0 ]; then
  # this is an installation path - installed=false
  show_message "INSTALLING" "OpenAuto is installing ..."

  if install_openauto; then
    log_message "Installation complete!\n"
    show_confirmation "DONE" "OpenAuto has been installed. System will reboot now. Remember to remove USB drive."
  else
    log_message "Installation Failed!\n"
    show_confirmation "FAILED" "OpenAuto Failed to install"
  fi
elif [ ${remove} -eq 1 ]; then
  # this is a removing path - installed=true, remove=true
  show_message "UNINSTALLING" "OpenAuto is uninstalling ..."

  remove_openauto

  log_message "Uninstall complete!\n"
  show_confirmation "DONE" "Uninstall complete. System will reboot now. Remember to remove USB drive."
else
  # this is an update path - installed=true, remove=false
  show_message "UPDATING" "Android Auto is updating ..."

  if install_openauto; then
    log_message "Update complete!\n"
    show_confirmation "DONE" "OpenAuto has been Updated. System will reboot now. Remember to remove USB drive."
  else
    log_message "Updated Failed!\n"
    show_confirmation "FAILED" "OpenAuto Failed to update"
  fi

  log_message "Update complete!\n"
fi

sleep 3
reboot
exit
