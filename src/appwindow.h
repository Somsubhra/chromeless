#ifndef APPWINDOW_H
#define APPWINDOW_H

// Qt includes
#include <QMainWindow>

// Other includes
#include "appview.h"

class AppWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AppWindow(QWidget *parent = 0);


private:
    AppView* appView;

signals:

public slots:

};

#endif // APPWINDOW_H
