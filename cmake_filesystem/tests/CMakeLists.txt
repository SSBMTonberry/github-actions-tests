project(cmake_filesystem_tests)

set(SOURCE_FILES main_tests.cpp ${PROJECT_SOURCE_DIR}/../src/FileManager.cpp)

# enable CTest testing
enable_testing()

add_executable(cmake_filesystem_tests ${SOURCE_FILES})

add_test(test_all cmake_filesystem_tests)