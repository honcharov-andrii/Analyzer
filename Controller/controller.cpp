#include "controller.hpp"

#include <iostream>
#include <map>
#include <thread>
#include <regex>

namespace Analyzer
{

Controller::Controller(const std::string & serviceName,
                       const std::string & inputDirectory,
                       const std::string & outputDirectory,
                       const std::set<std::string> & dataForExport,
                       Model & model) :
    mServiceName{serviceName},
    mInputDirectory{inputDirectory},
    mOutputDirectory{outputDirectory},
    mDataForExport{dataForExport},
    mLastTime{std::filesystem::file_time_type::min()},
    mModel{model}
{
}

void Controller::start()
{
    std::string regularExpressionString = "core\\." + mServiceName + "\\.([a-z0-9]+\\.)+lz4";
    std::regex regExpr (regularExpressionString);
    while (true)
    {
        std::map<std::filesystem::file_time_type, std::string> folderData =
        mModel.checkFolderForTheFiles(regExpr, mInputDirectory);

        if(false == folderData.empty() &&
           folderData.rbegin()->first.time_since_epoch().count() > mLastTime.time_since_epoch().count())
        {
            mLastTime = folderData.rbegin()->first;
            std::string pathToDirForArchive = mModel.createFolderForArchive(mOutputDirectory, mDataForExport);
            std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
            mModel.packTar(pathToDirForArchive, mOutputDirectory + "/" + std::to_string(ms.count()));
            std::filesystem::remove_all(pathToDirForArchive);
        }
        std::this_thread::yield();
#ifdef UNIT_TEST
        break;
#endif
    }
}

}
