#include "CkTar.h"
#include "model.hpp"

#include <chrono>
#include <iostream>
#include <filesystem>

namespace Analyzer
{

std::map<std::filesystem::file_time_type, std::string> Model::checkFolderForTheFiles(std::regex regExpr, std::string inputDirectory)
{
    std::map<std::filesystem::file_time_type, std::string> folderData;
    for (const auto & entry : std::filesystem::directory_iterator(inputDirectory))
    {
        if(true == std::regex_match(entry.path().filename().string(), regExpr))
        {
            folderData[entry.last_write_time()] = entry.path().string();
        }
    }
    return folderData;
}

std::string Model::createFolderForArchive(const std::string & pathToFolder, const std::set<std::string> & dataForExport)
{
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch());
    std::string  pathToFolderForArchive = pathToFolder + "/" + std::to_string(ms.count());
    std::filesystem::create_directories(pathToFolderForArchive);
    for (const auto & item : dataForExport)
    {
        std::filesystem::path path(item);
        if(true == std::filesystem::exists(path))
        {
            std::filesystem::copy(item,
                                  std::filesystem::path(pathToFolderForArchive + "/" + path.filename().string()),
                                  std::filesystem::copy_options::recursive);
        }
        else
        {
            std::cout << "File/Directory with next path: " << item << " is absent" << std::endl;
        }
    }

    return pathToFolderForArchive;
}

void Model::packTar(const std::string & pathToFolder, const std::string & pathForArchive)
{
    CkTar tar;
    // The TAR component will produce a  GNU tar 1.13.x format
    // archive by default.
    // It is also possible to create PAX -- POSIX 1003.1-2001 format
    // or USTAR -- POSIX 1003.1-1988 format.
    // Set the WriteFormat property to "gnu", "pax", or "ustar" to
    // choose the output TAR format:
    tar.put_WriteFormat("gnu");

    // Add a directory tree to be included in the output TAR archive:
    bool success = tar.AddDirRoot(pathToFolder.c_str());
    if (true != success)
    {
        std::cout << "Error during adding folder for archive: " << tar.lastErrorText() << std::endl;
        return;
    }

    // First write a .tar
    success = tar.WriteTar(std::string(pathForArchive + ".tar").c_str());
    if (true != success)
    {
        std::cout << "Error during .tar archive creating: " << tar.lastErrorText() << std::endl;
        return;
    }
}

void Model::removeFolder(const std::string & pathToFolder)
{
    std::filesystem::remove_all(pathToFolder);
}

}
