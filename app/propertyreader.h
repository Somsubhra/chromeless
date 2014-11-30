#ifndef PROPERTYREADER_H
#define PROPERTYREADER_H

#include <QObject>

class PropertyReader : public QObject
{
    Q_OBJECT
public:
    explicit PropertyReader(QObject *parent = 0);

    void readProperties(QString propFile);

signals:

public slots:

};

#endif // PROPERTYREADER_H
