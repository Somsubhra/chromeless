// Other includes
#include "appview.h"

AppView::AppView(QWidget *parent) :
    QWebView(parent)
{
}

void AppView::setAppRoot(QString appRoot)
{
    this->load(QUrl::fromLocalFile(appRoot));
}
