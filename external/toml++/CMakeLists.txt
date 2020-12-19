cmake_minimum_required(VERSION 3.0)

project(toml++)

add_library(toml++ INTERFACE)

target_include_directories(toml++ INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})