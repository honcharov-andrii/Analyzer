#ifndef VIEW_H
#define VIEW_H

#include <string>
#include <set>

namespace Analyzer
{

class View
{
public:
    View(int argc, char *argv[]);
    ~View() = default;
    std::string getServiceName();
    std::string getInputDirectory();
    std::string getOutputDirectory();
    std::set<std::string> getDataForExport();
private:
    View() = delete;
    std::string           mServiceName;
    std::string           mInputDirectory;
    std::string           mOutputDirectory;
    std::set<std::string> mDataForExport;
};

}

#endif // VIEW_H
