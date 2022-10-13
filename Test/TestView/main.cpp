#include "gtest/gtest.h"

#include "view.hpp"

class ViewTest : public ::testing::Test
{
public:
    ViewTest() {};

    virtual ~ViewTest(){};

    void SetUp(){};

    void TearDown(){};
};

TEST_F(ViewTest, testViewCorrectBehavior)
{
    char *arr[5];
    arr[0] = (char*)"pathToProgram";
    arr[1] = (char*)"ServiceName"; // name of the service
    arr[2] = (char*)"./"; // input dir for monitoring
    arr[3] = (char*)"./"; // output dir for saving
    arr[4] = (char*)"./"; // files for export

    EXPECT_NO_THROW(Analyzer::View view(5, arr));
}

//TEST(FooTest, testViewIncorrectNumOfArgument)
//{
//    char *arr[1];
//    arr[0] = (char*)"pathToProgram";
//
//    EXPECT_ANY_THROW(Analyzer::View view(1, arr));
//}

TEST_F(ViewTest, testViewIncorrectInputPath)
{
    int size = 5;
    char *arr[size];
    arr[0] = (char*)"pathToProgram";
    arr[1] = (char*)"ServiceName"; // name of the service
    arr[2] = (char*)"adcdf"; // input dir for monitoring
    arr[3] = (char*)"./"; // output dir for saving
    arr[4] = (char*)"./"; // files for export

    EXPECT_THROW((Analyzer::View{5, arr}), std::runtime_error);
}

TEST_F(ViewTest, testViewIncorrectOutputPath)
{
    size_t size = 5;
    char *arr[5];
    arr[0] = (char*)"pathToProgram";
    arr[1] = (char*)"ServiceName"; // name of the service
    arr[2] = (char*)"./"; // input dir for monitoring
    arr[3] = (char*)"asdf"; // output dir for saving
    arr[4] = (char*)"./"; // files for export

    EXPECT_ANY_THROW({
             Analyzer::View v(size, arr);
                         v.getDataForExport();
        });

    //EXPECT_THROW((Analyzer::View{5, arr}), std::runtime_error);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    int ret = RUN_ALL_TESTS();
    return ret;
}
