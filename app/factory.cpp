// Other includes
#include "factory.h"

Factory::Factory(int argc, char **argv, QString appPackage, QObject *parent) :
    QObject(parent)
{
    controlPanel = new ControlPanel();

    // Not a file open event
    if(appPackage == "") {
        appWindow = new AppWindow(argv[1]);

        if(argc == 2) {
            appWindow->show();
        } else {
            controlPanel->show();
        }

    } else {
        // A file open event
        appWindow = new AppWindow(appPackage);
        appWindow->show();
    }

}
