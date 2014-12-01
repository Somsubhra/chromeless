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
#include <QDebug>

// Other includes
#include "application.h"
#include "factory.h"

int main(int argc, char** argv) {

    Application app(argc, argv);

    QString appPackage = app.appPackage();

    Factory(&app, argc, argv, appPackage);

    return app.exec();
}
