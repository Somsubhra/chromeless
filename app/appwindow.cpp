// Other includes
#include "appwindow.h"

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowTitle(tr("Application Window"));

    appReader = new AppReader();

    appView = new AppView(this);
    this->setCentralWidget(appView);

    connect(this, SIGNAL(destroyed()), appReader, SLOT(cleanUp()));
}

void AppWindow::runAppPackage(QString appPackage)
{
    // Extract the app package in a tmp location
    appReader->readPackage(appPackage);

    // Pass the tmp location and render the extracted package
    appView->setAppRoot(appReader->appRoot());
}
