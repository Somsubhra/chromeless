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
#include "factory.h"

Factory::Factory(int argc, char **argv, QString appPackage, QObject *parent) :
    QObject(parent)
{
    controlPanel = new ControlPanel();

    // Not a file open event
    if(appPackage == "") {
        appWindow = new AppWindow(argv[1]);

        if(argc == 2) {
            appWindow->show();
        } else {
            controlPanel->show();
        }

    } else {
        // A file open event
        appWindow = new AppWindow(appPackage);
        appWindow->show();
    }

}
