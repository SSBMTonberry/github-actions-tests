project(cmake_filesystem_tests LANGUAGES CXX VERSION 0.0.1)

#find_package(Catch2 REQUIRED)

set(SOURCE_FILES main_tests.cpp ${PROJECT_SOURCE_DIR}/../src/FileManager.cpp)

add_executable(cmake_filesystem_tests ${SOURCE_FILES})

target_link_libraries(cmake_filesystem_tests cmake_filesystem)
#target_link_libraries(cmake_filesystem_tests Catch2::Catch2 )

#target_link_libraries(cmake_filesystem_tests
#        cmake_filesystem
#        Catch2::Test
#        )

add_test( NAME cmake_filesystem_tests COMMAND cmake_filesystem_tests -o report.xml -r junit)