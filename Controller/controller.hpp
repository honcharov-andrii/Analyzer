#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "imodel.hpp"

#include <filesystem>
#include <queue>
#include <string>
#include <set>

namespace Analyzer
{

class Controller
{
public:
    Controller(const std::string & serviceName,
               const std::string & inputDirectory,
               const std::string & outputDirectory,
               const std::set<std::string> & dataForExport,
               IModel & model);
    ~Controller() = default;
    void start();
private:
    Controller() = delete;
    std::string                     mServiceName;
    std::string                     mInputDirectory;
    std::string                     mOutputDirectory;
    std::set<std::string>           mDataForExport;
    std::filesystem::file_time_type mLastTime;
    IModel &                        mModel;
};

}

#endif // CONTROLLER_H
