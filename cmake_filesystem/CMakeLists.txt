cmake_minimum_required(VERSION 3.15)
project(cmake_filesystem)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_VERSION_MAJOR 0)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 1)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING
            "Choose the type of build, options are: Debug Release
RelWithDebInfo MinSizeRel."
            FORCE)
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(DEBUG 1)
    message(DEBUGGIN')
else()
    set(RELEASE 1)
endif()

set(LINUX 0)
set(WINDOWS 0)
set(APPLE 0)
set(MSVC 0)
set(MINGW 0)

if(UNIX AND NOT APPLE)
    set(LINUX 1)
elseif(APPLE)
    link_directories(/usr/local/opt/llvm/lib/)
    set(APPLE 1)
elseif(WIN32)
    set(WINDOWS 1)
    if(MSVC)
        set(MSVC 1)
    elseif(MINGW)
        set(MINGW 1)
    endif()
endif()

configure_file (
        "${PROJECT_SOURCE_DIR}/CMakeFilesystemConfig.h.in"
        "${PROJECT_SOURCE_DIR}/CMakeFilesystemConfig.h"
)

include_directories(${PROJECT_SOURCE_DIR}/external_libs/ )

set(SOURCE_FILES src/FileManager.cpp)

add_library(cmake_filesystem ${SOURCE_FILES})
add_subdirectory(external_libs)
add_subdirectory(tests)