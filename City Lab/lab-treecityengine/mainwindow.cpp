/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include "mainwindow.h"

#include "cityengine.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    m_engine = new CityEngine(this);
    m_model = new QStandardItemModel(this);

    setupTreeModel();
    // TASK: You will need a view to display the model
    // m_view = 
    // setCentralWidget(m_view);
}

void MainWindow::setupTreeModel()
{
    // TASK: Implement a tree model with standarditem model, displaying countries with their largest cities
    // The column header shall display "Country / City", "Population", "Area"
}
