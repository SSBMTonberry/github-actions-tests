project(cmake_filesystem_tests LANGUAGES CXX VERSION 0.0.1)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${PROJECT_SOURCE_DIR}/../external_libs)

set(SOURCE_FILES main_tests.cpp)

add_executable(cmake_filesystem_tests ${SOURCE_FILES})

target_link_libraries(cmake_filesystem_tests Catch cmake_filesystem)
#target_link_libraries(cmake_filesystem_tests Catch2::Catch2 )

#target_link_libraries(cmake_filesystem_tests
#        cmake_filesystem
#        Catch2::Test
#        )

include(CTest)
include(Catch)
catch_discover_tests(cmake_filesystem_tests)