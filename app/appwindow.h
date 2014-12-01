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

#ifndef APPWINDOW_H
#define APPWINDOW_H

// Qt includes
#include <QMainWindow>

// Other includes
#include "appview.h"
#include "appreader.h"
#include "propertyreader.h"
#include "application.h"

class AppWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit AppWindow(Application* app = 0, QString appPackage = "", QWidget *parent = 0);

private:
    void applyAppProperties();

private:
    AppView* appView;
    AppReader* appReader;
    PropertyReader* propReader;

signals:

public slots:

};

#endif // APPWINDOW_H
