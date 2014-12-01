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

#ifndef FACTORY_H
#define FACTORY_H

// Qt includes
#include <QObject>

// Other includes
#include "appwindow.h"
#include "controlpanel.h"

class Factory : public QObject
{
    Q_OBJECT
public:
    explicit Factory(int argc = 0, char** argv = 0, QString appPackage = "", QObject *parent = 0);

private:
    AppWindow* appWindow;
    ControlPanel* controlPanel;

signals:

public slots:

};

#endif // FACTORY_H
