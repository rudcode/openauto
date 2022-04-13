#include "com_jci_vbs_drvididm_objectProxy.h"

com_jci_vbs_drvididm_objectProxy::com_jci_vbs_drvididm_objectProxy(std::shared_ptr <DBus::Connection> conn,
                                                                   std::string dest,
                                                                   std::string path) : DBus::ObjectProxy(conn,
                                                                                                         dest,
                                                                                                         path) {
  m_com_jci_vbs_drvididmProxy = com_jci_vbs_drvididmProxy::create("com.jci.vbs.drvididm");
  this->add_interface(m_com_jci_vbs_drvididmProxy);

}
std::shared_ptr <com_jci_vbs_drvididm_objectProxy> com_jci_vbs_drvididm_objectProxy::create(std::shared_ptr <DBus::Connection> conn,
                                                                                            std::string dest,
                                                                                            std::string path,
                                                                                            DBus::ThreadForCalling signalCallingThread) {
  std::shared_ptr <com_jci_vbs_drvididm_objectProxy> created =
      std::shared_ptr<com_jci_vbs_drvididm_objectProxy>(new com_jci_vbs_drvididm_objectProxy(conn, dest, path));
  conn->register_object_proxy(created, signalCallingThread);
  return created;

}
std::shared_ptr <com_jci_vbs_drvididmProxy> com_jci_vbs_drvididm_objectProxy::getcom_jci_vbs_drvididmInterface() {
  return m_com_jci_vbs_drvididmProxy;

}
