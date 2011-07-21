#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dialog d(ui->horizontalSlider->value());
    if ( d.exec() == QDialog::Accepted )
    {
        ui->horizontalSlider->setValue(d.value());
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    Dialog *d = new Dialog(ui->horizontalSlider->value(), this);
    d->show();
    d->raise();
    d->activateWindow();

    QObject::connect(d, SIGNAL(accepted()),
                     this, SLOT(dialogAccepted()));
    QObject::connect(d, SIGNAL(rejected()),
                     this, SLOT(dialogRejected()));
}

void MainWindow::dialogAccepted()
{
    Dialog *d = qobject_cast<Dialog *>(sender());

    if ( ! d )
    {
        return;
    }

    int val = d->value();
    ui->horizontalSlider->setValue(val);
    d->deleteLater();
}

void MainWindow::dialogRejected()
{
    Dialog *d = qobject_cast<Dialog *>(sender());
    if ( ! d )
    {
        return;
    }

    d->deleteLater();
}

