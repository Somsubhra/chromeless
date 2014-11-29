// Qt includes
#include <QDebug>
#include <QDir>

// Third party includes
#include <quazip.h>
#include <quazipfile.h>

// Other includes
#include "appreader.h"

AppReader::AppReader()
{
    tempDir = new QTemporaryDir();
}

void AppReader::readPackage(QString appPackage)
{
    QuaZip zip(appPackage);

    zip.open(QuaZip::mdUnzip);

    QuaZipFile file(&zip);

    for(bool f = zip.goToFirstFile(); f; f = zip.goToNextFile()) {
        file.open(QIODevice::ReadOnly);
        qDebug() << zip.getCurrentFileName();
        qDebug() << file.readAll();
        file.close();
    }

    zip.close();
}

void AppReader::cleanUp()
{
    tempDir->remove();
}
