// Other includes
#include "appwindow.h"

AppWindow::AppWindow(QString appPackage, QWidget *parent) :
    QMainWindow(parent)
{
    appReader = new AppReader();
    appReader->readPackage(appPackage);

    propReader = new PropertyReader();
    propReader->readProperties(appReader->appProps());
    this->applyAppProperties();

    appView = new AppView(this);
    appView->setAppRoot(appReader->appRoot());
    this->setCentralWidget(appView);

    connect(this, SIGNAL(destroyed()), appReader, SLOT(cleanUp()));
}

void AppWindow::applyAppProperties()
{
    if(propReader->isAppNameSet()) {
        this->setWindowTitle(propReader->appName());
    }

    if(propReader->isWindowMaxWidthSet()) {
        this->setMaximumWidth(propReader->windowMaxWidth());
    }
    if(propReader->isWindowMaxHeightSet()) {
        this->setMaximumHeight(propReader->windowMaxHeight());
    }

    if(propReader->isWindowMinWidthSet()) {
        this->setMinimumWidth(propReader->windowMinWidth());
    }

    if(propReader->isWindowMinHeightSet()) {
        this->setMinimumHeight(propReader->windowMinHeight());
    }

    if(propReader->isWindowFixedWidthSet()) {
        this->setFixedWidth(propReader->windowFixedWidth());
    }

    if(propReader->isWindowFixedHeightSet()) {
        this->setFixedHeight(propReader->windowFixedHeight());
    }

    if(propReader->isWindowMaximizedSet()) {
        if(propReader->windowMaximized()) {
            this->setWindowState(Qt::WindowMaximized);
        }
    }
}
