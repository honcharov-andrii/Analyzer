#include <iostream>

#include "view.hpp"
#include "model.hpp"
#include "controller.hpp"

using namespace std;

int main(int argc, char *argv[])
{
    char *arr[5];
    arr[0] = (char*)"pathToProgram";
    arr[1] = (char*)"ServiceName"; // name of the service
    arr[2] = (char*)"/home/ahoncharov/Desktop/inputDir"; // input dir for monitoring
    arr[3] = (char*)"/home/ahoncharov/Desktop/outputDir"; // output dir for saving
    arr[4] = (char*)"/home/ahoncharov/Desktop/inputDir/serviceName/1.txt"; // files for export

    Analyzer::View view(5, arr);
    Analyzer::Model model;
    Analyzer::Controller c(view.getServiceName(),
                           view.getInputDirectory(),
                           view.getOutputDirectory(),
                           view.getDataForExport(),
                           model);
    c.start();
    return 0;
}
