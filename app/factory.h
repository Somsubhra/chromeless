#ifndef FACTORY_H
#define FACTORY_H

// Qt includes
#include <QObject>

// Other includes
#include "appwindow.h"
#include "controlpanel.h"

class Factory : public QObject
{
    Q_OBJECT
public:
    explicit Factory(int argc = 0, char** argv = 0, QString appPackage = "", QObject *parent = 0);

private:
    AppWindow* appWindow;
    ControlPanel* controlPanel;

signals:

public slots:

};

#endif // FACTORY_H
