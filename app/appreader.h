#ifndef APPREADER_H
#define APPREADER_H

// Qt includes
#include <QObject>
#include <QTemporaryDir>

class AppReader : public QObject
{
    Q_OBJECT
public:
    explicit AppReader(QObject* parent = 0);

    void readPackage(QString appPackage);

    QString appRoot();

    QString appProps();

private:
    QTemporaryDir* tempDir;

public slots:
    void cleanUp();
};

#endif // APPREADER_H
