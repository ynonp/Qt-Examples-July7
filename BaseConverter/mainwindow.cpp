#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "baseconverter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->btnGo, SIGNAL(clicked()),
                     this, SLOT(convert()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::convert()
{
    BaseConverter b;
    int dec = QString(ui->edtDec->text()).toInt();
    QString hex = b.toHex(dec);
    QString binary = b.toBinary(dec);

    ui->lblBinary->setText(binary);
    ui->lblHex->setText(hex);
}

