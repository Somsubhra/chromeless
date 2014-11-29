// Other includes
#include "appwindow.h"

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowTitle(tr("Application Window"));

    appView = new AppView(this);
    this->setCentralWidget(appView);
}
