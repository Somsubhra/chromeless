#ifndef APPREADER_H
#define APPREADER_H

// Qt includes
#include <QObject>
#include <QTemporaryDir>

class AppReader : public QObject
{
    Q_OBJECT
public:
    AppReader();

    void readPackage(QString appPackage);

    QString appRoot();

private:
    QTemporaryDir* tempDir;

public slots:
    void cleanUp();
};

#endif // APPREADER_H
