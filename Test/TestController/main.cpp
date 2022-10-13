#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "controller.hpp"

class ControllerTest : public ::testing::Test
{
public:
    ControllerTest() {};

    virtual ~ControllerTest(){};

    void SetUp(){};

    void TearDown(){};
};

class ModelMock : public Analyzer::IModel
{
public:
    ModelMock() = default;
    ~ModelMock() = default;
    MOCK_METHOD((std::map<std::filesystem::file_time_type, std::string>), checkFolderForTheFiles, (std::regex regExpr, std::string inputDirectory));
    MOCK_METHOD(std::string, createFolderForArchive, (const std::string & pathToFolder, const std::set<std::string> & dataForExport));
    MOCK_METHOD(void, packTar, (const std::string & pathToFolder, const std::string & pathForArchive));
    MOCK_METHOD(void, removeFolder, (const std::string & pathToFolder));
};

TEST_F(ControllerTest, testControllerwork)
{
    std::string fileName1 = std::filesystem::current_path().string() + "/" +"core.ServiceName.3717.1647975805000000.lz4";
    std::string fileName2 = std::filesystem::current_path().string() + "/" +"1.txt";

    ModelMock modelMock;
    std::map<std::filesystem::file_time_type, std::string> returnMap;
    returnMap.insert({std::filesystem::file_time_type(), fileName1});
    EXPECT_CALL(modelMock, checkFolderForTheFiles(testing::_, std::filesystem::current_path().string())).WillOnce(testing::Return(returnMap));
    std::set<std::string> dataForExport {fileName2};
    EXPECT_CALL(modelMock, createFolderForArchive(std::filesystem::current_path().string(), dataForExport)).WillOnce(testing::Return(std::filesystem::current_path().string()));
    EXPECT_CALL(modelMock, packTar(std::filesystem::current_path().string(), testing::_));
    EXPECT_CALL(modelMock, removeFolder(std::filesystem::current_path().string()));
    Analyzer::Controller controller("ServiceName",
                                    std::filesystem::current_path().string(),
                                    std::filesystem::current_path().string(),
                                    {fileName2},
                                    modelMock);
    controller.start();
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
