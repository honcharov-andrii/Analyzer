#include "view.hpp"
#include <stdexcept>
#include <filesystem>

#include <iostream>

namespace
{
    size_t const INDEX_OF_SERVICE_NAME          = 1;
    size_t const INDEX_OF_INPUT_DIR             = 2;
    size_t const INDEX_OF_OUTPUT_DIR            = 3;
    size_t const INDEX_OF_DATA_FOR_EXPORT_BEGIN = 4;
    size_t const MIN_NUMBER_OF_ARGS             = 5;
}

namespace Analyzer
{

View::View(int argc, char *argv[]) :
    mServiceName{},
    mInputDirectory{},
    mOutputDirectory{},
    mDataForExport{}
{
    if(argc < MIN_NUMBER_OF_ARGS)
    {
        std::runtime_error("Too few arguments");
    }

    std::cout << "I am here 1" << std::endl;
    if(false == std::filesystem::exists(std::filesystem::path(argv[INDEX_OF_INPUT_DIR])))
    {
        std::cout << "I am here 2" << std::endl;
        std::runtime_error("Input directory is not exist");
    }

    if(false == std::filesystem::exists(std::filesystem::path(argv[INDEX_OF_OUTPUT_DIR])))
    {
        std::runtime_error("Output directory is not exist");
    }

    mServiceName =     argv[INDEX_OF_SERVICE_NAME];
    mInputDirectory =  argv[INDEX_OF_INPUT_DIR];
    mOutputDirectory = argv[INDEX_OF_OUTPUT_DIR];

    for (int i = INDEX_OF_DATA_FOR_EXPORT_BEGIN; i < argc; ++i)
    {
        mDataForExport.insert(argv[i]);
    }
}

std::string View::getServiceName()
{
    return mServiceName;
}

std::string View::getInputDirectory()
{
    return mInputDirectory;
}

std::string View::getOutputDirectory()
{
    return mOutputDirectory;
}

std::set<std::string> View::getDataForExport()
{
    return mDataForExport;
}

}
