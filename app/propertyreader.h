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
    bool windowMaximized();

    // Getters for the flags
    bool isAppVersionSet();
    bool isAppNameSet();
    bool isAppDescSet();
    bool isAuthorNameSet();
    bool isAuthorEmailSet();
    bool isWindowHeightSet();
    bool isWindowWidthSet();
    bool isWindowMaxWidthSet();
    bool isWindowMaxHeightSet();
    bool isWindowMinWidthSet();
    bool isWindowMinHeightSet();
    bool isWindowFixedWidthSet();
    bool isWindowFixedHeightSet();
    bool isWindowShowTitleBarSet();
    bool isWindowMaximizedSet();

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
    bool _winMaximized;

    // Set/Unset Flags
    bool _isAppVersionSet;
    bool _isAppNameSet;
    bool _isAppDescSet;
    bool _isAuthorNameSet;
    bool _isAuthorEmailSet;
    bool _isWinHeightSet;
    bool _isWinWidthSet;
    bool _isWinMaxWidthSet;
    bool _isWinMaxHeightSet;
    bool _isWinMinWidthSet;
    bool _isWinMinHeightSet;
    bool _isWinFixedWidthSet;
    bool _isWinFixedHeightSet;
    bool _isWinShowTitleBarSet;
    bool _isWinMaximizedSet;

signals:

public slots:

};

#endif // PROPERTYREADER_H
