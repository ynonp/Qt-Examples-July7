#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QFileSystemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
    QStandardItemModel *model = new QStandardItemModel(this);
    for ( int i=0; i< 10; ++i )
    {
        QStandardItem *it = new QStandardItem(QString("%1").arg(i));
        it->setData(Qt::green, Qt::DecorationRole);
        model->appendRow(it);
    }
    */

    QFileSystemModel *model = new QFileSystemModel(this);
    model->setRootPath("/");

    ui->tableView->setModel(model);
    ui->listView->setModel(model);
    ui->treeView->setModel(model);
    ui->tableView->setSelectionModel(ui->listView->selectionModel());
    ui->tableView->hide();
    ui->listView->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}
