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
#include <QStyle>
#include <QToolBar>
#include <QFileDialog>

// Other includes
#include "controlpanel.h"
#include "appwindow.h"

ControlPanel::ControlPanel(Application *app, QWidget *parent) :
    QMainWindow(parent)
{
    application = app;

    this->setFixedSize(320, 320);
    this->setWindowTitle(tr("Lils Control Panel"));

    QMenu* appMenu = menuBar()->addMenu(tr("App"));

    QAction* runAppAction = new QAction(style()->standardIcon(QStyle::SP_MediaPlay), tr("Run App"), appMenu);
    connect(runAppAction, SIGNAL(triggered()), this, SLOT(runAppPressed()));
    runAppAction->setShortcut(QKeySequence("Ctrl+O"));
    appMenu->addAction(runAppAction);

    QAction* exitAction = new QAction(style()->standardIcon(QStyle::SP_DialogCloseButton), tr("Exit"), appMenu);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
    exitAction->setShortcut(QKeySequence("Ctrl+X"));
    appMenu->addAction(exitAction);

    QMenu* aboutMenu = menuBar()->addMenu(tr("About"));

    QAction* aboutAction = new QAction(style()->standardIcon(QStyle::SP_MessageBoxInformation), tr("About"), aboutMenu);
    connect(aboutAction, SIGNAL(triggered()), this, SLOT(aboutPressed()));
    aboutAction->setShortcut(QKeySequence("Ctrl+A"));
    aboutMenu->addAction(aboutAction);

    QAction* licenseAction = new QAction(style()->standardIcon(QStyle::SP_FileDialogDetailedView), tr("Licenses"), aboutMenu);
    connect(licenseAction, SIGNAL(triggered()), this, SLOT(licensePressed()));
    licenseAction->setShortcut(QKeySequence("Ctrl+L"));
    aboutMenu->addAction(licenseAction);

    QToolBar* mainWidget = new QToolBar(this);
    mainWidget->setIconSize(QSize(320, 320));
    mainWidget->addAction(runAppAction);

    this->setCentralWidget(mainWidget);
}

void ControlPanel::runAppPressed()
{
    QString appPackage = QFileDialog::getOpenFileName(this, "Select App Package", QDir::currentPath(), tr("Lils App (*.lx)"));
    AppWindow* window = new AppWindow(application, appPackage);
    window->show();
}

void ControlPanel::licensePressed()
{

}

void ControlPanel::aboutPressed()
{

}
