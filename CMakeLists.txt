cmake_minimum_required(VERSION 3.5.1)
project(openauto CXX)

set(base_directory ${CMAKE_CURRENT_SOURCE_DIR})
set(sources_directory ${base_directory}/src)
set(include_directory ${base_directory}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${base_directory}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${base_directory}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${base_directory}/bin)
set(EXECUTABLE_OUTPUT_PATH ${base_directory}/bin)

set(OPENSSL_USE_STATIC_LIBS TRUE) #Statically link openssl for Mazda target
set(Protobuf_USE_STATIC_LIBS ON) #Statically link protobuf for Mazda target

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")
SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} -Wall -pedantic -fPIC -s")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3")

find_package(libusb-1.0 REQUIRED)
find_package(Protobuf REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ALSA REQUIRED)
find_package(PkgConfig REQUIRED)
find_package(asio REQUIRED)
pkg_check_modules(GST REQUIRED gstreamer-0.10
        gstreamer-video-0.10
        gstreamer-app-0.10
        gstreamer-audio-0.10
        )
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(UDEV REQUIRED libudev)
pkg_check_modules(DBUS REQUIRED dbus-1)
pkg_check_modules(DBUS_C++ REQUIRED dbus-c++-1)
pkg_check_modules(SIGC++ REQUIRED sigc++-2.0)

message("CMAKE_CURRENT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}")
message("CMAKE_BINARY_DIR ${CMAKE_BINARY_DIR}")


file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated/Mazda/Dbus/)
file(GLOB_RECURSE dbus_xml ${include_directory}/Mazda/Dbus/XML/*.xml)
set(GEN_DBUS_HEADER_COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/dbusxx-xml2cpp)
foreach (header ${dbus_xml})
    get_filename_component(header_out ${header} NAME_WLE)
    message("Adding ${header} to be compiled to ${header_out}.h")
    add_custom_command( #TARGET dbus_proxy_headers POST_BUILD
            OUTPUT "Mazda/Dbus/${header_out}.h"
            COMMAND ${GEN_DBUS_HEADER_COMMAND} ${header} --proxy="${header_out}.h"
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated/Mazda/Dbus/
            COMMENT "Generating" ${dbus_xml})
endforeach ()

include_directories(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_BINARY_DIR}
        ${LIBUSB_1_INCLUDE_DIRS}
        ${PROTOBUF_INCLUDE_DIR}
        ${OPENSSL_INCLUDE_DIR}
        ${AASDK_PROTO_INCLUDE_DIRS}
        ${AASDK_INCLUDE_DIRS}
        ${GLIB_INCLUDE_DIRS}
        ${GST_INCLUDE_DIRS}
        ${ALSA_INCLUDE_DIRS}
        ${DBUS_C++_INCLUDE_DIRS}
        ${DBUS_C++-GLIB_INCLUDE_DIRS}
        ${SIGC++_INCLUDE_DIRS}
        ${ASIO_INCLUDE_DIRS})

link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(common_include_directory ${include_directory}/f1x/openauto/Common)

set(autoapp_sources_directory ${sources_directory}/autoapp)
set(autoapp_include_directory)
file(GLOB_RECURSE autoapp_source_files ${autoapp_sources_directory}/*.cpp)

add_executable(autoapp
        ${autoapp_source_files}
        ${sources_directory}/easylogging++.cc
        "Mazda/Dbus/com.jci.nativeguictrl.h"
        "Mazda/Dbus/com.jci.bucpsa.h")
target_include_directories(autoapp PUBLIC ${CMAKE_CURRENT_BINARY_DIR}/generated/ ${common_include_directory})
target_include_directories(autoapp PRIVATE ${include_directory})

target_link_libraries(autoapp
        libsigc-2.0.a
        ${UDEV_LIBRARIES}
        libusb-1.0.a
        ${GLIB_LIBRARIES}
        ${GST_LIBRARIES}
        ${ALSA_LIBRARIES}
        ${CMAKE_SYSROOT}/usr/lib/libaasdk.a
        ${CMAKE_SYSROOT}/usr/lib/libaasdk_proto.a
        ${Protobuf_LIBRARIES}
        OpenSSL::Crypto
        OpenSSL::SSL
        ${ASIO_LIBRARIES}
        ${CMAKE_SYSROOT}/usr/lib/libdbus-c++-1.a
        ${CMAKE_SYSROOT}/usr/lib/libdbus-1.a
        -static-libstdc++
        )

#set(btservice_sources_directory ${sources_directory}/btservice)
#set(btservice_include_directory ${include_directory}/f1x/openauto/btservice)
#file(GLOB_RECURSE btservice_source_files ${btservice_sources_directory}/*.cpp ${btservice_include_directory}/*.hpp ${common_include_directory}/*.hpp)
#
#add_executable(btservice
#        ${btservice_source_files}
#        "Mazda/Dbus/com.jci.bds.h"
#        "Mazda/Dbus/com.jci.bca.h")
#target_include_directories(btservice PUBLIC ${include_directory}/Mazda/Dbus ${common_include_directory})
#target_include_directories(btservice PRIVATE ${include_directory})
#
#
#target_link_libraries(btservice
#        ${CMAKE_SYSROOT}/usr/lib/libaasdk_proto.a
#        ${Protobuf_LITE_LIBRARIES}
#        ${CMAKE_SYSROOT}/usr/lib/libdbus-c++-1.a
#        ${CMAKE_SYSROOT}/usr/lib/libdbus-1.a
#        Threads::Threads
#        -static-libstdc++
#        -lrt)
