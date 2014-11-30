#ifndef APPWINDOW_H
#define APPWINDOW_H

// Qt includes
#include <QMainWindow>

// Other includes
#include "appview.h"
#include "appreader.h"
#include "propertyreader.h"

class AppWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AppWindow(QWidget *parent = 0);

    void runAppPackage(QString appPackage);

private:
    AppView* appView;
    AppReader* appReader;
    PropertyReader* propReader;

signals:

public slots:

};

#endif // APPWINDOW_H
