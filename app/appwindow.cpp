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

// Other includes
#include "appwindow.h"

AppWindow::AppWindow(Application *app, QString appPackage, QWidget *parent) :
    QMainWindow(parent)
{
    appReader = new AppReader();
    appReader->readPackage(appPackage);

    propReader = new PropertyReader();
    propReader->readProperties(appReader->appProps());
    this->applyAppProperties();

    appView = new AppView(this);
    appView->setAppRoot(appReader->appRoot());
    this->setCentralWidget(appView);

    connect(app, SIGNAL(aboutToQuit()), appReader, SLOT(cleanUp()));
}

void AppWindow::applyAppProperties()
{
    if(propReader->isAppNameSet()) {
        this->setWindowTitle(propReader->appName());
    }

    if(propReader->isWindowMaxWidthSet()) {
        this->setMaximumWidth(propReader->windowMaxWidth());
    }
    if(propReader->isWindowMaxHeightSet()) {
        this->setMaximumHeight(propReader->windowMaxHeight());
    }

    if(propReader->isWindowMinWidthSet()) {
        this->setMinimumWidth(propReader->windowMinWidth());
    }

    if(propReader->isWindowMinHeightSet()) {
        this->setMinimumHeight(propReader->windowMinHeight());
    }

    if(propReader->isWindowFixedWidthSet()) {
        this->setFixedWidth(propReader->windowFixedWidth());
    }

    if(propReader->isWindowFixedHeightSet()) {
        this->setFixedHeight(propReader->windowFixedHeight());
    }

    if(propReader->isWindowMaximizedSet()) {
        if(propReader->windowMaximized()) {
            this->setWindowState(Qt::WindowMaximized);
        }
    }

    if(propReader->isWindowHideTitleBarSet()) {
        if(propReader->windowHideTitleBar()) {
            this->setWindowFlags(Qt::FramelessWindowHint);
        }
    }
}
