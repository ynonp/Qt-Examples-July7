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
    m_model = new ItemModel();

    setupTreeModel();
    // TASK: You will need a view to display the model

    QWidget *container = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(container);

    QHBoxLayout *findLayout = new QHBoxLayout();
    layout->addLayout(findLayout);
    findLayout->addWidget(new QLabel("Find:"));
    m_find = new QLineEdit();
    findLayout->addWidget(m_find);
    connect(m_find, SIGNAL(textChanged(QString)), this, SLOT(onFindChanged(QString)));


    m_view = new QTreeView(this);
    m_view->setModel(m_model);
    layout->addWidget(m_view);

    connect(m_view, SIGNAL(clicked(QModelIndex)), this, SLOT(onClicked(QModelIndex)));


    setCentralWidget(container);

}

void MainWindow::setupTreeModel()
{
    // TASK: Implement a tree model with standarditem model, displaying countries with their largest cities

    QStringList countries = m_engine->countries();

    QStringList headerLabels;
    headerLabels << "Country / City" << "Poulation" << "Area";
    m_model->setHorizontalHeaderLabels(headerLabels);

    foreach(const QString& country, countries) {
        QIcon flag = m_engine->flag(country);
        Item *countryItem = new Item(flag, country); // top-level item

        QStringList cities = m_engine->citiesByCountry(country);
        foreach(const QString& city, cities) {

            QList<Item*> items;
            items << new Item(city);
            items << new Item(QString::number(m_engine->population(city)));
            items << new Item(QString::number(m_engine->area(city)));

            countryItem->appendRow(items); // append child items to top-level item

        }

        m_model->appendRow(countryItem);
    }
}


void MainWindow::onClicked(const QModelIndex &index) {
    Item *item = m_model->itemFromIndex(index);
    qDebug() << "item clicked " << item->text();

    qDebug() << "    text on index" << index.data(Qt::DisplayRole).toString();
    qDebug() << "    position = " << index.row() << " " << index.column();
}

void MainWindow::onFindChanged(const QString &text)
{
    if(text.isEmpty()) {
        m_view->selectionModel()->clear();
        return;
    }
    QList<Item*> items = m_model->findItems(text, Qt::MatchContains);
    m_view->selectionModel()->clear();
    foreach(Item *item, items) {
        m_view->selectionModel()->select(item->index(), QItemSelectionModel::Select);
    }
}
