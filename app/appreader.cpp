/*
 *  Copyright (c) 2014 Somsubhra Bairi <somsubhra.bairi@gmail.com>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 */

// Qt includes
#include <QDir>

// Third party includes
#include <quazip.h>
#include <quazipfile.h>

// Other includes
#include "appreader.h"

AppReader::AppReader(QObject *parent)
    : QObject(parent)
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

QString AppReader::appRoot()
{
    return QDir(tempDir->path()).absoluteFilePath("index.html");
}

QString AppReader::appProps()
{
    return QDir(tempDir->path()).absoluteFilePath("app.json");
}

void AppReader::cleanUp()
{
    tempDir->remove();
}
