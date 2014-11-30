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

    return app.exec();
}
