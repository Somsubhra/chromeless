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

private:
    QTemporaryDir* tempDir;

public slots:
    void cleanUp();
};

#endif // APPREADER_H
