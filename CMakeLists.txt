cmake_minimum_required(VERSION 3.5.1)
project(openauto CXX)

set(base_directory ${CMAKE_CURRENT_SOURCE_DIR})
set(resources_directory ${base_directory}/assets)
set(sources_directory ${base_directory}/src)
set(include_directory ${base_directory}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${base_directory}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${base_directory}/lib)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${base_directory}/bin)
set(EXECUTABLE_OUTPUT_PATH ${base_directory}/bin)

set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
set(OPENSSL_USE_STATIC_LIBS TRUE) #Statically link openssl for Mazda target
set(Protobuf_USE_STATIC_LIBS ON) #Statically link protobuf for Mazda target

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake_modules/")
SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS_INIT} -Wall -pedantic -fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-g -O3")

#add_definitions(-DBOOST_ALL_DYN_LINK)

find_package(Boost REQUIRED COMPONENTS system log OPTIONAL_COMPONENTS unit_test_framework)
find_package(libusb-1.0 REQUIRED)
find_package(Protobuf REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(ALSA REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GST REQUIRED gstreamer-0.10
        gstreamer-video-0.10
        gstreamer-app-0.10
        gstreamer-audio-0.10
        )
pkg_check_modules(GLIB REQUIRED glib-2.0)
pkg_check_modules(UDEV REQUIRED libudev)
pkg_check_modules(DBUS REQUIRED dbus-1)
pkg_check_modules(DBUS_C++ REQUIRED dbus-c++-1)

if(WIN32)
    set(WINSOCK2_LIBRARIES "ws2_32")
endif(WIN32)

if(RPI3_BUILD)
    add_definitions(-DUSE_OMX -DOMX_SKIP64BIT -DRASPBERRYPI3)
    set(BCM_HOST_LIBRARIES "/opt/vc/lib/libbcm_host.so")
    set(BCM_HOST_INCLUDE_DIRS "/opt/vc/include")
    set(ILCLIENT_INCLUDE_DIRS "/opt/vc/src/hello_pi/libs/ilclient")
    set(ILCLIENT_LIBRARIES "/opt/vc/src/hello_pi/libs/ilclient/libilclient.a;/opt/vc/lib/libvcos.so;/opt/vc/lib/libvcilcs.a;/opt/vc/lib/libvchiq_arm.so")
endif(RPI3_BUILD)

include_directories(${CMAKE_CURRENT_BINARY_DIR}
                    ${Boost_INCLUDE_DIRS}
                    ${LIBUSB_1_INCLUDE_DIRS}
                    ${PROTOBUF_INCLUDE_DIR}
                    ${OPENSSL_INCLUDE_DIR}
                    ${AASDK_PROTO_INCLUDE_DIRS}
                    ${AASDK_INCLUDE_DIRS}
                    ${GLIB_INCLUDE_DIRS}
                    ${GST_INCLUDE_DIRS}
                    ${include_directory}
                    ${ALSA_INCLUDE_DIRS}
                    ${DBUS_C++_INCLUDE_DIRS}
                    ${DBUS_C++-GLIB_INCLUDE_DIRS})
								
link_directories(${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

set(common_include_directory ${include_directory}/f1x/openauto/Common)

set(autoapp_sources_directory ${sources_directory}/autoapp)
set(autoapp_include_directory ${include_directory}/f1x/openauto/autoapp)
file(GLOB_RECURSE autoapp_source_files ${autoapp_sources_directory}/*.ui ${autoapp_sources_directory}/*.cpp ${autoapp_include_directory}/*.hpp ${common_include_directory}/*.hpp ${resources_directory}/*.qrc)

add_executable(autoapp ${autoapp_source_files})

target_link_libraries(autoapp
                        ${Boost_LIBRARIES}
                        ${UDEV_LIBRARIES}
                        libusb-1.0.a
                        ${PROTOBUF_LIBRARIES}
                        ${GLIB_LIBRARIES}
                        ${GST_LIBRARIES}
                        ${ALSA_LIBRARIES}
                        ${CMAKE_SYSROOT}/usr/lib/libaasdk_proto.so
                        ${CMAKE_SYSROOT}/usr/lib/libaasdk.so
                        OpenSSL::Crypto
                        OpenSSL::SSL
                        -static-libstdc++)

set(btservice_sources_directory ${sources_directory}/btservice)
set(btservice_include_directory ${include_directory}/f1x/openauto/btservice)
file(GLOB_RECURSE btservice_source_files ${btservice_sources_directory}/*.cpp ${btservice_include_directory}/*.hpp ${common_include_directory}/*.hpp)
#
add_executable(btservice ${btservice_source_files})

target_link_libraries(btservice
                        ${Boost_LIBRARIES}
                        ${PROTOBUF_LIBRARIES}
                        ${CMAKE_SYSROOT}/usr/lib/libaasdk_proto.so
        ${CMAKE_SYSROOT}/usr/lib/libdbus-c++-1.a
        ${CMAKE_SYSROOT}/usr/lib/libdbus-1.a
        Threads::Threads
        -static-libstdc++
        -lrt)
