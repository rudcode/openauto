cmake_minimum_required(VERSION 3.0)

project(easylogging++)

add_compile_definitions(ELPP_THREAD_SAFE)

add_library(easylogging++ STATIC easylogging++.cc)

target_include_directories(easylogging++ INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
