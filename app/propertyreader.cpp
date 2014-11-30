// Qt includes
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QDebug>

// Other includes
#include "propertyreader.h"

PropertyReader::PropertyReader(QObject *parent) :
    QObject(parent)
{
}

void PropertyReader::readProperties(QString propFile)
{
    QFile file(propFile);
    file.open(QIODevice::ReadOnly);

    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(file.readAll(), &err);

    // If error in parsing the document, then return
    if(err.error != QJsonParseError::NoError) {
        return;
    }

    QJsonObject jObj = doc.object();

    qDebug() << jObj["author"].toObject()["name"].toString();

    file.close();
}

QString PropertyReader::appVersion()
{
    return _appVersion;
}

QString PropertyReader::appName()
{
    return _appName;
}

QString PropertyReader::appDesc()
{
    return _appDesc;
}

QString PropertyReader::authorName()
{
    return _authorName;
}

QString PropertyReader::authorEmail()
{
    return _authorEmail;
}

int PropertyReader::windowHeight()
{
    return _winHeight;
}

int PropertyReader::windowWidth()
{
    return _winWidth;
}

int PropertyReader::windowMaxWidth()
{
    return _winMaxWidth;
}

int PropertyReader::windowMaxHeight()
{
    return _winMaxHeight;
}

int PropertyReader::windowMinWidth()
{
    return _winMinWidth;
}

int PropertyReader::windowMinHeight()
{
    return _winMinHeight;
}

int PropertyReader::windowFixedWidth()
{
    return _winFixedWidth;
}

int PropertyReader::windowFixedHeight()
{
    return _winFixedHeight;
}

bool PropertyReader::windowShowTitleBar()
{
    return _winShowTitleBar;
}
