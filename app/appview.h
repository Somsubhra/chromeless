#ifndef APPVIEW_H
#define APPVIEW_H

// Qt includes
#include <QWebView>

class AppView : public QWebView
{
    Q_OBJECT
public:
    explicit AppView(QWidget *parent = 0);

    void setAppRoot(QString appRoot);

signals:

public slots:

};

#endif // APPVIEW_H
