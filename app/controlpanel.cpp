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
#include <QMenuBar>

// Other includes
#include "controlpanel.h"

ControlPanel::ControlPanel(QWidget *parent) :
    QMainWindow(parent)
{
    this->setMaximumSize(640, 480);
    this->setMinimumSize(320, 240);
    this->setWindowTitle(tr("Lils Control Panel"));

    QMenu* appMenu = menuBar()->addMenu(tr("App"));

    QAction* openAppAction = new QAction(tr("Open App"), appMenu);
    openAppAction->setShortcut(QKeySequence("Ctrl+O"));
    appMenu->addAction(openAppAction);

    QAction* exitAction = new QAction(tr("Exit"), appMenu);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    exitAction->setShortcut(QKeySequence("Ctrl+X"));
    appMenu->addAction(exitAction);

    QMenu* aboutMenu = menuBar()->addMenu(tr("About"));

    QAction* aboutAction = new QAction(tr("About"), aboutMenu);
    aboutAction->setShortcut(QKeySequence("Ctrl+A"));
    aboutMenu->addAction(aboutAction);

    QAction* licenseAction = new QAction(tr("Licenses"), aboutMenu);
    licenseAction->setShortcut(QKeySequence("Ctrl+L"));
    aboutMenu->addAction(licenseAction);
}
