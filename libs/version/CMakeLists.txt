cmake_minimum_required(VERSION 3.12)
project(tea24)

configure_file(
    version_config.h.in
    version_config.h
    @ONLY
)

add_library(version STATIC
    version.cpp
    version.h
)

target_include_directories(version PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}       
    ${CMAKE_CURRENT_BINARY_DIR}       
)