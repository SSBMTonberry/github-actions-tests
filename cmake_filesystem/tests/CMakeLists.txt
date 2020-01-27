project(cmake_filesystem_tests)

set(SOURCE_FILES main_tests.cpp ${PROJECT_SOURCE_DIR}/../src/FileManager.cpp)

add_executable(cmake_filesystem_tests ${SOURCE_FILES})