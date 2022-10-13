#ifndef IMODEL_H
#define IMODEL_H

#include <filesystem>
#include <map>
#include <regex>
#include <set>
#include <string>


namespace Analyzer
{

class IModel
{
public:
    virtual std::map<std::filesystem::file_time_type, std::string> checkFolderForTheFiles(std::regex regExpr, std::string inputDirectory) = 0;
    virtual std::string createFolderForArchive(const std::string & pathToFolder, const std::set<std::string> & dataForExport) = 0;
    virtual void packTar(const std::string & pathToFolder, const std::string & pathForArchive) = 0;
    virtual void removeFolder(const std::string & pathToFolder) = 0;
};

}

#endif // IMODEL_H
