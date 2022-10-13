#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>

#include "gtest/gtest.h"

#include "controller.hpp"

class ControllerTest : public ::testing::Test
{
public:
    ControllerTest() {};

    virtual ~ControllerTest(){};

    void SetUp(){};

    void TearDown(){};
};

TEST_F(ControllerTest, testModelCheckFolderForTheFiles)
{
    std::string fileName1 = std::filesystem::current_path().string() + "/" +"core.ServiceName.3717.1647975805000000.lz4";
    std::ofstream ofs1(fileName1);
    ofs1.close();

    std::string fileName2 = std::filesystem::current_path().string() + "/" +"1.txt";
    std::ofstream ofs2(fileName2);
    ofs2.close();

    char *arr[5];
    arr[0] = (char*)"pathToProgram";
    arr[1] = (char*)"ServiceName"; // name of the service
    arr[2] = (char*)std::filesystem::current_path().string().c_str(); // input dir for monitoring
    arr[3] = (char*)std::filesystem::current_path().string().c_str(); // output dir for saving
    arr[4] = (char*)fileName2.c_str(); // files for export

    Analyzer::Model model;
    Analyzer::Controller c(arr[1], arr[2], arr[3], {arr[4]}, model);

    std::filesystem::remove_all(fileName1);
    std::filesystem::remove_all(fileName2);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
