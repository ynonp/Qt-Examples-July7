#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    iScene = new QGraphicsScene(this);
    ui->graphicsView->setScene(iScene);

    iBall = new QGraphicsEllipseItem(0 , 0, 20, 20);
    iBall->setBrush(QBrush(Qt::green));
    iScene->addItem(iBall);

    iTimer.start(1000 / 36);
    QObject::connect(&iTimer, SIGNAL(timeout()),
                     this, SLOT(tick()));
    iDirection.rx() = 5;
    iDirection.ry() = 5;

    qDebug() << iBall->pos();
}


void MainWindow::tick()
{
    float ballWidth = iBall->boundingRect().size().width();
    float ballHeight = iBall->boundingRect().size().height();

    QPoint pos = iBall->pos();

    if ( ( pos.x() + iDirection.x() + ballWidth / 2  > ui->graphicsView->size().width())
         || ( pos.x() < 0) )
    {
        qDebug() << iBall->pos();
        iDirection.rx() *= -1;
    }

    if ( ( iBall->pos().y() + iDirection.y() + ballHeight / 2 > ui->graphicsView->size().height())
         || ( iBall->pos().y() < 0 ) )
    {
        qDebug() << iBall->pos();
        iDirection.ry() *= -1;
    }

    iBall->setPos(iBall->pos().x() + iDirection.x(), iBall->pos().y() + iDirection.y());
}

MainWindow::~MainWindow()
{
    delete ui;
}
