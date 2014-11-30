#ifndef APPLICATION_H
#define APPLICATION_H

// Qt includes
#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int argc = 0, char **argv = 0);

    QString appPackage();

protected:
    bool event(QEvent *event);

private:
    QString appPkg;

signals:

public slots:

};

#endif // APPLICATION_H
