// Qt includes
#include <QDebug>

// Other includes
#include "application.h"
#include "controlpanel.h"
#include "appwindow.h"

int main(int argc, char** argv) {

    Application app(argc, argv);

    ControlPanel panel;
    AppWindow appWindow;

    QString appPackage = app.appPackage();

    // Not a file open event
    if(appPackage == "") {
        switch(argc) {
            // Open the control panel
            case 1:
                panel.show();
                break;

            // Run the application package
            case 2:
                appWindow.show();
                appWindow.runAppPackage(argv[1]);
                break;

            // Other options
            default:
                panel.show();
                break;
        }
    } else {
        // A file open event
        appWindow.show();
        appWindow.runAppPackage(appPackage);
    }

    return app.exec();
}
