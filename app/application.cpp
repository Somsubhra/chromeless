// Qt includes
#include <QFileOpenEvent>

// Other includes
#include "application.h"

Application::Application(int argc, char** argv) :
    QApplication(argc, argv)
{
    appPkg = "";
}


bool Application::event(QEvent *event)
{
    switch(event->type()) {

        case QEvent::FileOpen:
            // Somehow load file here
            appPkg = static_cast<QFileOpenEvent*>(event)->file();
            return true;

        default:
            return QApplication::event(event);
    }
}

QString Application::appPackage()
{
    return appPkg;
}
