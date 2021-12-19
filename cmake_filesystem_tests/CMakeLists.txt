project(cmake_filesystem_tests LANGUAGES CXX VERSION 0.0.1)

#add_library(Catch INTERFACE)
#target_include_directories(Catch INTERFACE ${PROJECT_SOURCE_DIR}/../external_libs)

CPMFindPackage(
        NAME Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.4
        EXCLUDE_FROM_ALL YES
)

set(SOURCE_FILES main_tests.cpp)

add_executable(cmake_filesystem_tests ${SOURCE_FILES})

#target_link_libraries(cmake_filesystem_tests Catch cmake_filesystem)



if(LINUX)
    target_link_libraries(cmake_filesystem_tests cmake_filesystem Catch2::Catch2 )
elseif(WIN32)
    if(MSVC)
        target_link_libraries(cmake_filesystem_tests cmake_filesystem Catch2::Catch2 )
    else()
        target_link_libraries(cmake_filesystem_tests cmake_filesystem stdc++fs Catch2::Catch2 )
    endif()
elseif(APPLE)
    target_link_libraries(cmake_filesystem_tests cmake_filesystem Catch2::Catch2 stdc++ /usr/local/opt/llvm/lib/libc++experimental.a /usr/local/opt/llvm/lib/libc++fs.a)
endif()

#target_link_libraries(cmake_filesystem_tests
#        cmake_filesystem
#        Catch2::Test
#        )

enable_testing()

include(CTest)
include(Catch)
catch_discover_tests(cmake_filesystem_tests WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")