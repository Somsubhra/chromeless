#include "appwindow.h"

AppWindow::AppWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowTitle(tr("Application Window"));
}
