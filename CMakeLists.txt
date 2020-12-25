cmake_minimum_required(VERSION 3.5.1)
project(openauto CXX)

set(base_directory ${CMAKE_CURRENT_SOURCE_DIR})
set(sources_directory ${base_directory}/src)
set(include_directory ${base_directory}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${base_directory}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${base_directory}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${base_directory}/bin)
set(EXECUTABLE_OUTPUT_PATH ${base_directory}/bin)

SET(CMAKE_FIND_LIBRARY_SUFFIXES ".a")
SET(BUILD_SHARED_LIBS OFF)
set(CMAKE_LINK_SEARCH_START_STATIC ON)
set(OPENSSL_USE_STATIC_LIBS TRUE) #Statically link openssl for Mazda target
set(Protobuf_USE_STATIC_LIBS ON) #Statically link protobuf for Mazda target

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")
SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} -Wall -pedantic -Wno-psabi")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3")

message("CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS}")

find_package(Protobuf REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ALSA REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(asio REQUIRED)
find_package(sdbus-c++ REQUIRED)
#pkg_check_modules(DBUS REQUIRED dbus-1)
#pkg_check_modules(DBUS_C++ REQUIRED dbus-c++-1)
pkg_check_modules(SIGC++ REQUIRED sigc++-2.0)
pkg_check_modules(LIBUSB REQUIRED libusb-1.0)
pkg_check_modules(Systemd REQUIRED libsystemd)
pkg_check_modules(LIBEVDEV REQUIRED libevdev)


SET(USE_STANDALONE_ASIO ON CACHE BOOL "use standalone Asio")
SET(USE_OPENSSL OFF CACHE BOOL "Don't need SSL in our webserver")
add_subdirectory(external/Simple-Web-Server)

set(JSON_BuildTests OFF CACHE INTERNAL "")
set(JSON_Install OFF CACHE INTERNAL "")
add_subdirectory(external/json)

set(BUILD_SHARED_LIBS OFF CACHE INTERNAL "")
set(BUILD_TESTS OFF CACHE INTERNAL "")
add_subdirectory(external/tinyxml2)

add_compile_definitions(ELPP_THREAD_SAFE)
add_subdirectory(external/easylogging++)

add_subdirectory(external/toml++)


find_package(Git)
if (GIT_EXECUTABLE)
    execute_process(
            WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
            COMMAND "${GIT_EXECUTABLE}" describe --tags --always
            OUTPUT_VARIABLE GIT_HASH
            OUTPUT_STRIP_TRAILING_WHITESPACE
    )
    set(BUILD_HASH ${GIT_HASH})

    if (NOT REPRODUCIBLE)
        execute_process(
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                COMMAND "whoami"
                OUTPUT_VARIABLE GIT_USER
                OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        execute_process(
                WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                COMMAND "hostname"
                OUTPUT_VARIABLE GIT_HOST
                OUTPUT_STRIP_TRAILING_WHITESPACE
        )
        string(REGEX REPLACE "([^\\])[\\]([^\\])" "\\1\\\\\\\\\\2" GIT_USER ${GIT_USER})
        set(BUILD_HASH ${GIT_USER}@${GIT_HOST}-${GIT_HASH})
    endif ()

    message("Git commit hash: ${BUILD_HASH}")

    configure_file(cmake/version.in.h ${CMAKE_CURRENT_BINARY_DIR}/version.h @ONLY)
endif ()


file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated/Mazda/Dbus/)
file(GLOB_RECURSE dbus_xml ${include_directory}/Mazda/Dbus/XML/*.xml)
set(GEN_DBUS_HEADER_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/sdbus-c++-xml2cpp)
foreach (header ${dbus_xml})
    get_filename_component(header_file ${header} NAME)
    string(REGEX REPLACE "\\.[^.]*$" "" header_out ${header_file})
    message("Adding ${header} to be compiled to ${header_out}.h")
    add_custom_command( #TARGET dbus_proxy_headers POST_BUILD
            OUTPUT "Mazda/Dbus/${header_out}.h"
            COMMAND ${GEN_DBUS_HEADER_COMMAND} ${header} --proxy="${header_out}.h"
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated/Mazda/Dbus/
            COMMENT "Generating" ${dbus_xml})
endforeach ()

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_BINARY_DIR}
        ${LIBUSB_INCLUDE_DIRS}
        ${PROTOBUF_INCLUDE_DIR}
        ${OPENSSL_INCLUDE_DIR}
        ${AASDK_PROTO_INCLUDE_DIRS}
        ${AASDK_INCLUDE_DIRS}
        ${ALSA_INCLUDE_DIRS}
        #        ${DBUS_C++_INCLUDE_DIRS}
        #        ${DBUS_C++-GLIB_INCLUDE_DIRS}
        ${SIGC++_INCLUDE_DIRS}
        ${ASIO_INCLUDE_DIRS}
        ${LIBEVDEV_INCLUDE_DIRS})

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(autoapp_sources_directory ${sources_directory}/autoapp)
set(autoapp_include_directory)
file(GLOB_RECURSE autoapp_source_files ${autoapp_sources_directory}/*.cpp)

add_executable(autoapp
        ${autoapp_source_files}
        "Mazda/Dbus/com.jci.nativeguictrl.h"
        "Mazda/Dbus/com.jci.bucpsa.h"
        "Mazda/Dbus/com.xsembedded.ServiceProvider.h"
        "Mazda/Dbus/com.jci.lds.control.h"
        "Mazda/Dbus/com.jci.lds.data.h"
        "Mazda/Dbus/com.jci.pa.h"
        "Mazda/Dbus/com.jci.bds.h"
        "Mazda/Dbus/com.jci.bca.h")
target_include_directories(autoapp PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/generated/)
target_include_directories(autoapp PRIVATE ${include_directory})

target_compile_options(autoapp PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

target_link_libraries(autoapp
        ${SIGC++_LIBRARIES}
        ${LIBUSB_LIBRARIES}
        ${ALSA_LIBRARIES}
        ${CMAKE_SYSROOT}/usr/lib/libaasdk.a
        ${CMAKE_SYSROOT}/usr/lib/libaasdk_proto.a
        ${Protobuf_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        ${LIBEVDEV_LIBRARIES}
        #        ${CMAKE_SYSROOT}/usr/lib/libdbus-c++-1.a
        #        ${CMAKE_SYSROOT}/usr/lib/libdbus-1.a
        ${CMAKE_SYSROOT}/usr/lib/libsdbus-c++.a
        ${CMAKE_SYSROOT}/usr/lib/libsystemd.a
        ${CMAKE_SYSROOT}/usr/lib/libcap.a
        simple-web-server
        nlohmann_json::nlohmann_json
        easylogging++
        toml++
        tinyxml2
        -static
        -static-libstdc++
        -static-libgcc
        -pthread
        )

add_custom_command(
        TARGET autoapp
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} --only-keep-debug autoapp autoapp.debug
        WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
)
add_custom_command(
        TARGET autoapp
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} --strip-all autoapp
        WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
)
add_custom_command(
        TARGET autoapp
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} --add-gnu-debuglink=autoapp.debug autoapp
        WORKING_DIRECTORY ${EXECUTABLE_OUTPUT_PATH}
)