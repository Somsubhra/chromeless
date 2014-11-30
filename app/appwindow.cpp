// Other includes
#include "appwindow.h"

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowTitle(tr("Application Window"));

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

    // Pass the tmp location and render the extracted package
    appView->setAppRoot(appReader->appRoot());
}
