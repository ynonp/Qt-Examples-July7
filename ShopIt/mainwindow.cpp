#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "additemdlg.h"
#include <QDebug>
#include "shoppingitem.h"
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->btnAdd, SIGNAL(clicked()),
                     this, SLOT(showAddItemDialog()));

    QObject::connect(ui->btnRemove, SIGNAL(clicked()),
                     this, SLOT(removeSelectedItem()));

    QObject::connect(ui->btnSave, SIGNAL(clicked()),
                     this, SLOT(saveList()));

    QObject::connect(ui->btnLoad, SIGNAL(clicked()),
                     this, SLOT(loadList()));

    QObject::connect(ui->listWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)),
                     this, SLOT(editItem(QListWidgetItem *)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAddItemDialog()
{
    AddItemDlg dlg;
    if ( dlg.exec() )
    {
        // dialog was accepted - add the item
        ShoppingItem item(dlg.getName(), dlg.getPrice(), dlg.getQty());
        addShoppingItem(&item);
    }
}

void MainWindow::removeSelectedItem()
{
    ui->listWidget->takeItem(ui->listWidget->currentRow());
}

void MainWindow::saveList()
{
    QString saveFilename = QFileDialog::getSaveFileName();
    QFile   saveFile(saveFilename);

    if ( saveFile.open(QIODevice::WriteOnly) )
    {
        QDataStream out(&saveFile);
        int count = ui->listWidget->count();
        for ( int i=0; i < count; ++i )
        {
            QListWidgetItem *item = ui->listWidget->item(i);
            QVariant shoppingVar  = item->data(Qt::UserRole);
            ShoppingItem shopping = shoppingVar.value<ShoppingItem>();
            out << shopping;
        }

        saveFile.close();
    }
    else
    {
        QMessageBox::warning(this,
                             tr("Failed to open file for writing"),
                             QString(saveFile.error()),
                             QMessageBox::Ok);
    }

}

void MainWindow::loadList()
{
    QString listFilename = QFileDialog::getOpenFileName();
    QFile   listFile(listFilename);

    if ( listFile.open(QIODevice::ReadOnly) )
    {
        QDataStream in(&listFile);
        while ( ! in.atEnd() )
        {
            ShoppingItem item;
            in >> item;
            addShoppingItem(&item);
        }

        listFile.close();
    }
    else
    {
        QMessageBox::warning(this,
                             tr("Failed to open file for reading"),
                             QString(listFile.error()),
                             QMessageBox::Ok);
    }

}

void MainWindow::addShoppingItem(ShoppingItem *item)
{
    QVariant iv;
    iv.setValue(*item);

    QListWidgetItem *li = new QListWidgetItem(ui->listWidget);
    li->setText(item->getName());
    li->setData(Qt::UserRole, iv);
}

void MainWindow::editItem(QListWidgetItem *item)
{
    QVariant sv = item->data(Qt::UserRole);
    ShoppingItem prevShoppingItem = sv.value<ShoppingItem>();
    AddItemDlg dlg;
    dlg.setItem(prevShoppingItem);

    if ( dlg.exec() )
    {
        ShoppingItem shoppingItem(dlg.getName(), dlg.getPrice(), dlg.getQty());
        QVariant sv;
        sv.setValue(shoppingItem);

        item->setData(Qt::UserRole, sv);
        item->setText(shoppingItem.getName());
    }
}

