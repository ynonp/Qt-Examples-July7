/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#include <QtGui>

#include "cityengine.h"
#include "citytablemodel.h"

int main( int argc, char** argv ) {
    QApplication app( argc, argv );


    CityEngine *engine = new CityEngine(QCoreApplication::instance());
    CityTableModel *model = new CityTableModel(QCoreApplication::instance());
    model->setInput(engine);
    QListView* list = new QListView;
    list->setModel( model );
    list->setWindowTitle( "QListView" );
    list->show();

    QTreeView* tree = new QTreeView;
    tree->setModel( model );
    tree->setWindowTitle( "QTreeView" );
    tree->show();

    QTableView* table = new QTableView;
    table->setModel( model );
    table->setWindowTitle( "QTableView" );
    table->show();

    return app.exec();
}
