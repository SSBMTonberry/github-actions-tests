//
// Created by robin on 27.01.2020.
//

#ifndef CMAKE_FILESYSTEM_FILEMANAGER_H
#define CMAKE_FILESYSTEM_FILEMANAGER_H

#include "../CMakeFilesystemConfig.h"

#if MSVC
#include <filesystem>
    namespace fs = std::filesystem;
#elif MINGW
#if __MINGW64_VERSION_MAJOR > 6
        #include <filesystem>
        namespace fs = std::filesystem;
    #else
        #include <experimental/filesystem>
        namespace fs = std::experimental::filesystem;
    #endif
#elif APPLE
#if __clang_major__ < 8
#include <experimental/filesystem>
        namespace fs = std::experimental::filesystem;
    #else
        #include <filesystem>
        namespace fs = std::filesystem;
    #endif
#else
#if __GNUC__ < 8 //GCC major version less than 8
#include <experimental/filesystem>
                namespace fs = std::experimental::filesystem;
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif
#endif


class FileManager
{
    public:
        FileManager();
        int getNumberOfFilesHere();
    private:
    #if APPLE
            fs::path getMacApplicationFolder();
    #endif
        fs::path m_path =  "./";
};


#endif //CMAKE_FILESYSTEM_FILEMANAGER_H
