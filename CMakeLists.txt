cmake_minimum_required(VERSION 3.15)
project(github_actions_test)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/modules)

include_directories(${PROJECT_SOURCE_DIR}/external_libs)

# a better way to load dependencies
include(CPM)
add_subdirectory(cmake_filesystem)
add_subdirectory(cmake_filesystem_tests)