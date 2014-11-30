// Other includes
#include "appwindow.h"

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent)
{
    appReader = new AppReader();

    propReader = new PropertyReader();

    appView = new AppView(this);
    this->setCentralWidget(appView);

    connect(this, SIGNAL(destroyed()), appReader, SLOT(cleanUp()));
}

void AppWindow::runAppPackage(QString appPackage)
{
    // Extract the app package in a tmp location
    appReader->readPackage(appPackage);

    // Read the app properties
    propReader->readProperties(appReader->appProps());

    // Apply all the properties to the application
    this->applyAppProperties();

    // Pass the tmp location and render the extracted package
    appView->setAppRoot(appReader->appRoot());
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

    if(propReader->isWindowShowTitleBarSet()) {
        if(!propReader->windowShowTitleBar()) {
            this->setWindowFlags(Qt::FramelessWindowHint);
        }
    }
}
