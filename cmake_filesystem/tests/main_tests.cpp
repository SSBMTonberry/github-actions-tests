//
// Created by robin on 27.01.2020.
//

#define CATCH_CONFIG_MAIN
#include <catch.hpp>
#include "../src/FileManager.h"

TEST_CASE("Expect any file where test is ran", "[test][files]")
{
    FileManager manager;
    int number = manager.getNumberOfFilesHere();
    REQUIRE(number > 0);
}