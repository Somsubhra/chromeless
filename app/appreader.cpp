// Qt includes
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

    QDir parentDir = QDir(tempDir->path());

    // Extract the zip file in a temporary directory
    for(bool f = zip.goToFirstFile(); f; f = zip.goToNextFile()) {
        file.open(QIODevice::ReadOnly);

        QString newFilePath = parentDir.absoluteFilePath(zip.getCurrentFileName());

        QFile newFile(newFilePath);
        QFileInfo newFileInfo(newFile);

        newFile.open(QIODevice::WriteOnly);

        // Make sure that the file path exists
        parentDir.mkpath(newFileInfo.path());

        newFile.write(file.readAll());

        newFile.close();

        file.close();
    }

    zip.close();
}

void AppReader::cleanUp()
{
    tempDir->remove();
}
