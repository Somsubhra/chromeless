// Other includes
#include "controlpanel.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowState(Qt::WindowMaximized);
    this->setWindowTitle(tr("Control Panel"));
}
