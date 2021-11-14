project(cmake_filesystem_tests)

set(SOURCE_FILES main_tests.cpp ${PROJECT_SOURCE_DIR}/../src/FileManager.cpp)

# enable CTest testing
enable_testing()

add_executable(cmake_filesystem_tests ${SOURCE_FILES})

target_link_libraries(cmake_filesystem_tests
        cmake_filesystem
        Catch2::Test
        )

add_test(test_all cmake_filesystem_tests)