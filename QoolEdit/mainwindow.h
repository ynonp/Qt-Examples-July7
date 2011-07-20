#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void openFile();
    void saveFile();

    void about();
    void aboutQt();

private:
    void saveFile(QString filename);
    bool loadFile(QString filename);


private:
    Ui::MainWindow *ui;

    QString iFilename;
};

#endif // MAINWINDOW_H
