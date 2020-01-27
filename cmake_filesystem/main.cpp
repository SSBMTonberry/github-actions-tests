#include <iostream>
#include "src/FileManager.h"


int main()
{
    FileManager manager {};
    int files = manager.getNumberOfFilesHere();
    std::cout << "Hello, World!" << std::endl;
    std::cout << files << " files here!" << std::endl;
    return 0;
}
