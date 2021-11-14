project(cmake_filesystem_tests LANGUAGES CXX VERSION 0.0.1)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${PROJECT_SOURCE_DIR}/external_libs)

set(SOURCE_FILES main_tests.cpp ${PROJECT_SOURCE_DIR}/../src/FileManager.cpp)

add_executable(cmake_filesystem_tests ${SOURCE_FILES})

target_link_libraries(cmake_filesystem_tests cmake_filesystem)
target_link_libraries(cmake_filesystem_tests Catch)
#target_link_libraries(cmake_filesystem_tests Catch2::Catch2 )

#target_link_libraries(cmake_filesystem_tests
#        cmake_filesystem
#        Catch2::Test
#        )

enable_testing()
add_test( NAME TESTINATOR COMMAND cmake_filesystem_tests )