#include "factory.h"

Factory::Factory(int argc, char **argv, QString appPackage, QObject *parent) :
    QObject(parent)
{
    appWindow = new AppWindow();
    controlPanel = new ControlPanel();

    // Not a file open event
    if(appPackage == "") {

        if(argc == 2) {
            appWindow->show();
            appWindow->runAppPackage(argv[1]);
        } else {
            controlPanel->show();
        }

    } else {
        // A file open event
        appWindow->show();
        appWindow->runAppPackage(appPackage);
    }

}
