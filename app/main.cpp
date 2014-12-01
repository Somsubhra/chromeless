// Qt includes
#include <QDebug>

// Other includes
#include "application.h"
#include "controlpanel.h"
#include "appwindow.h"

int main(int argc, char** argv) {

    Application app(argc, argv);

    AppWindow appWindow;
    ControlPanel controlPanel;

    QString appPackage = app.appPackage();

    // Not a file open event
    if(appPackage == "") {

        if(argc == 2) {
            appWindow.show();
            appWindow.runAppPackage(argv[1]);
        } else {
            controlPanel.show();
        }

    } else {
        // A file open event
        appWindow.show();
        appWindow.runAppPackage(appPackage);
    }

    return app.exec();
}
