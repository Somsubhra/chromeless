#ifndef PROPERTYREADER_H
#define PROPERTYREADER_H

// Qt includes
#include <QObject>

class PropertyReader : public QObject
{
    Q_OBJECT
public:
    explicit PropertyReader(QObject *parent = 0);

    void readProperties(QString propFile);

    QString appVersion();
    QString appName();
    QString appDesc();

    QString authorName();
    QString authorEmail();

    int windowHeight();
    int windowWidth();
    int windowMaxWidth();
    int windowMaxHeight();
    int windowMinWidth();
    int windowMinHeight();
    int windowFixedWidth();
    int windowFixedHeight();
    bool windowShowTitleBar();

private:
    QString _appVersion;
    QString _appName;
    QString _appDesc;

    QString _authorName;
    QString _authorEmail;

    int _winHeight;
    int _winWidth;
    int _winMaxWidth;
    int _winMaxHeight;
    int _winMinWidth;
    int _winMinHeight;
    int _winFixedWidth;
    int _winFixedHeight;
    bool _winShowTitleBar;

signals:

public slots:

};

#endif // PROPERTYREADER_H
