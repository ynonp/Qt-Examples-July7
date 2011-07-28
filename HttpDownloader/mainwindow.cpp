#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QNetworkRequest>
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(startDownload()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startDownload()
{
    QString saveName = QFileDialog::getSaveFileName();

    if ( saveName.isEmpty() || saveName.isNull() )
    {
        return;
    }

    iSaveFileName = saveName;
    startDownload(ui->lineEdit->text());
}

void MainWindow::saveFile()
{
    QNetworkReply *reply = qobject_cast<QNetworkReply *>(sender());
    if ( reply )
    {
        QByteArray buf = reply->readAll();
        QFile f(iSaveFileName);
        if ( f.open(QIODevice::WriteOnly) )
        {
            f.write(buf);
        }
        reply->deleteLater();
    }
}

void MainWindow::startDownload(const QString &url)
{
    QUrl qurl(url);
    QNetworkReply *reply = iNam.get(QNetworkRequest(qurl));

    QObject::connect(reply, SIGNAL(finished()),
                     this, SLOT(saveFile()));

}

