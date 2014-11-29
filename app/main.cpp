// Qt includes
#include <QApplication>
#include <QDebug>

// Other includes
#include "controlpanel.h"
#include "appwindow.h"

int main(int argc, char** argv) {

    QApplication app(argc, argv);

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
            break;

        // Other options
        default:
            panel.show();
            break;
    }

    return app.exec();
}
