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

#ifndef PROPERTYREADER_H
#define PROPERTYREADER_H

// Qt includes
#include <QObject>

class PropertyReader : public QObject
{
    Q_OBJECT
public:
    explicit PropertyReader(QObject *parent = 0);

    void readProperties(QString propFile);

    QString appVersion();
    QString appName();
    QString appDesc();

    QString authorName();
    QString authorEmail();

    int windowMaxWidth();
    int windowMaxHeight();
    int windowMinWidth();
    int windowMinHeight();
    int windowFixedWidth();
    int windowFixedHeight();
    bool windowMaximized();
    bool windowHideTitleBar();

    // Getters for the flags
    bool isAppVersionSet();
    bool isAppNameSet();
    bool isAppDescSet();
    bool isAuthorNameSet();
    bool isAuthorEmailSet();
    bool isWindowMaxWidthSet();
    bool isWindowMaxHeightSet();
    bool isWindowMinWidthSet();
    bool isWindowMinHeightSet();
    bool isWindowFixedWidthSet();
    bool isWindowFixedHeightSet();
    bool isWindowMaximizedSet();
    bool isWindowHideTitleBarSet();

private:
    QString _appVersion;
    QString _appName;
    QString _appDesc;

    QString _authorName;
    QString _authorEmail;

    int _winMaxWidth;
    int _winMaxHeight;
    int _winMinWidth;
    int _winMinHeight;
    int _winFixedWidth;
    int _winFixedHeight;
    bool _winMaximized;
    bool _winHideTitleBar;

    // Set/Unset Flags
    bool _isAppVersionSet;
    bool _isAppNameSet;
    bool _isAppDescSet;
    bool _isAuthorNameSet;
    bool _isAuthorEmailSet;
    bool _isWinMaxWidthSet;
    bool _isWinMaxHeightSet;
    bool _isWinMinWidthSet;
    bool _isWinMinHeightSet;
    bool _isWinFixedWidthSet;
    bool _isWinFixedHeightSet;
    bool _isWinMaximizedSet;
    bool _isWinHideTitleBarSet;

signals:

public slots:

};

#endif // PROPERTYREADER_H
