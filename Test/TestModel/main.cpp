#include <iostream>
#include <filesystem>
#include <fstream>
#include <regex>

#include "gtest/gtest.h"

#include "model.hpp"

class ModelTest : public ::testing::Test
{
public:
    ModelTest() {};

    virtual ~ModelTest(){};

    void SetUp(){};

    void TearDown(){};
};

TEST_F(ModelTest, testModelCheckFolderForTheFiles)
{
    std::string regularExpressionString = "core\\.ServiceName\\.([a-z0-9]+\\.)+lz4";
    std::regex regExpr(regularExpressionString);
    std::string fileName = std::filesystem::current_path().string() + "/" +"core.ServiceName.3717.1647975805000000.lz4";
    std::ofstream ofs(fileName);
    ofs.close();

    Analyzer::Model model;
    std::map<std::filesystem::file_time_type, std::string> m =
    model.checkFolderForTheFiles(regExpr, std::filesystem::current_path().string());
    EXPECT_EQ(fileName, m.begin()->second);
    std::filesystem::remove_all(fileName);
}

TEST_F(ModelTest, testModelCreateFolderForArchive)
{
    std::string fileName = std::filesystem::current_path().string() + "/" +"test.txt";
    std::ofstream ofs(fileName);
    ofs.close();

    Analyzer::Model model;
    std::string  resultDir = model.createFolderForArchive(std::filesystem::current_path().string(), {fileName});

    EXPECT_EQ(true, std::filesystem::exists(resultDir));
    EXPECT_EQ(true, std::filesystem::exists(resultDir+ "/" +"test.txt"));

    std::filesystem::remove_all(fileName);
    std::filesystem::remove_all(resultDir);
}

TEST_F(ModelTest, testModelPackTar)
{
    Analyzer::Model model;
    std::filesystem::create_directories(std::filesystem::current_path().string() + "/" +"TestFolder");
    model.packTar(std::filesystem::current_path().string() + "/" +"TestFolder",
                  std::filesystem::current_path().string() + "/" +"TestArchive");
    EXPECT_EQ(true, std::filesystem::exists(std::filesystem::current_path().string() + "/" +"TestArchive.tar"));
    std::filesystem::remove_all(std::filesystem::current_path().string() + "/" +"TestFolder");
    std::filesystem::remove_all(std::filesystem::current_path().string() + "/" +"TestArchive.tar");
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
