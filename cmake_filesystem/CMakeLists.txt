cmake_minimum_required(VERSION 3.15)
project(cmake_filesystem)

configure_file (
        "${PROJECT_SOURCE_DIR}/CMakeFilesystemConfig.h.in"
        "${PROJECT_SOURCE_DIR}/CMakeFilesystemConfig.h"
)

#include_directories(${PROJECT_SOURCE_DIR}/external_libs/catch2/single_include/catch2)

set(SOURCE_FILES src/FileManager.cpp)

add_library(cmake_filesystem ${SOURCE_FILES})