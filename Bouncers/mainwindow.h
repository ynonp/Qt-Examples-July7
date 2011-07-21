#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QPoint>

class QGraphicsEllipseItem;
class QGraphicsScene;
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void tick();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *iScene;
    QGraphicsEllipseItem *iBall;
    QTimer iTimer;
    QPoint iDirection;
};

#endif // MAINWINDOW_H
