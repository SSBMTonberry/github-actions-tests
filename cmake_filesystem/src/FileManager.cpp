//
// Created by robin on 27.01.2020.
//

#include "FileManager.h"

FileManager::FileManager()
{
    #if APPLE
    m_path = getMacApplicationFolder();
    #else
    m_path = fs::current_path();
    #endif
}

int FileManager::getNumberOfFilesHere()
{
    int count = 0;
    for(auto &item : fs::directory_iterator(m_path))
    {
        if(item.is_regular_file())
        {
            std::cout << "Path: " << item << std::endl;
            ++count;
        }
    }
    return count;
}

#if APPLE
fs::path FileManager::getMacApplicationFolder()
{
    char buf [PATH_MAX];
    uint32_t bufsize = PATH_MAX;
    if(!_NSGetExecutablePath(buf, &bufsize))
        puts(buf);

    fs::path path {buf};
    return path;
}
#endif