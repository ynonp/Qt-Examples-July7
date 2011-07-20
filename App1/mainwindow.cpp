#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->actionOpen, SIGNAL(triggered()),
                     this, SLOT(openFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::openFile()
{
    qDebug() << "Open file clicked !";
}

