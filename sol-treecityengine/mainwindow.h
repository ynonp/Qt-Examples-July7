/*************************************************************************
 *
 * Copyright (c) 2008-2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

class CityEngine;

// !!! Typedefs for Qt classes !!!
typedef QStandardItemModel ItemModel;
typedef QStandardItem Item;


class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    void setupTreeModel();
private slots:
    void onClicked(const QModelIndex &index);
    void onFindChanged(const QString& text);
private:
    ItemModel *m_model;
    CityEngine *m_engine;
    QTreeView *m_view;
    QLineEdit *m_find;


};

#endif // MAINWINDOW_H
