#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->actionOpen, SIGNAL(triggered()),
                     this, SLOT(openFile()));

    QObject::connect(ui->actionSave, SIGNAL(triggered()),
                     this, SLOT(saveFile()));

    QObject::connect(ui->edtMain, SIGNAL(modificationChanged(bool)),
                     this, SLOT(setWindowModified(bool)));

    QObject::connect(ui->actionAbout, SIGNAL(triggered()),
                     this, SLOT(about()));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("Qool Edit"),
                       tr("The second best editor in the world"));
}

void MainWindow::aboutQt()
{
    QMessageBox::aboutQt(this, tr("About Qt"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveFile()
{
    if ( iFilename.isNull() || iFilename.isEmpty() )
    {
        iFilename = QFileDialog::getSaveFileName();
    }

    saveFile(iFilename);
}

void MainWindow::openFile()
{
    QString fname = QFileDialog::getOpenFileName();
    if ( loadFile(fname) )
    {
        iFilename = fname;
    }
}

void MainWindow::saveFile(QString filename)
{
    QFile f(filename);
    if ( f.open(QIODevice::WriteOnly) )
    {
        QTextStream fout(&f);
        fout << ui->edtMain->toPlainText();
        ui->edtMain->setWindowModified(false);
    }
    f.close();
}

bool MainWindow::loadFile(QString filename)
{
    QFile f(filename);
    if ( f.open(QIODevice::ReadOnly) )
    {
        QByteArray buf = f.readAll();
        ui->edtMain->setPlainText(buf);
        f.close();
        return true;
    }
    return false;
}
