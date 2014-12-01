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

#ifndef APPLICATION_H
#define APPLICATION_H

// Qt includes
#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT
public:
    explicit Application(int argc = 0, char **argv = 0);

    QString appPackage();

protected:
    bool event(QEvent *event);

private:
    QString appPkg;

signals:

public slots:

};

#endif // APPLICATION_H
