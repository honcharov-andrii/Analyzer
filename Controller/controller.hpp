#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "model.hpp"

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
               Model & model);
    ~Controller() = default;
    void start();
private:
    Controller() = delete;
    std::string                     mServiceName;
    std::string                     mInputDirectory;
    std::string                     mOutputDirectory;
    std::set<std::string>           mDataForExport;
    std::filesystem::file_time_type mLastTime;
    Model &                         mModel;
};

}

#endif // CONTROLLER_H
