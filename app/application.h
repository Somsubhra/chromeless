#ifndef APPLICATION_H
#define APPLICATION_H

#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int argc = 0, char **argv = 0);

signals:

public slots:

};

#endif // APPLICATION_H
