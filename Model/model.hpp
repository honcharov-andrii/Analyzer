#ifndef MODEL_H
#define MODEL_H

#include "imodel.hpp"

#include <filesystem>
#include <map>
#include <regex>
#include <set>
#include <string>


namespace Analyzer
{

class Model : public IModel
{
public:
    Model() = default;
    ~Model() = default;
    std::map<std::filesystem::file_time_type, std::string> checkFolderForTheFiles(std::regex regExpr, std::string inputDirectory);
    std::string createFolderForArchive(const std::string & pathToFolder, const std::set<std::string> & dataForExport);
    void packTar(const std::string & pathToFolder, const std::string & pathForArchive);
    void removeFolder(const std::string & pathToFolder);
};

}

#endif // MODEL_H
