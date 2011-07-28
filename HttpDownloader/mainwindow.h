#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>

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
    void startDownload();
    void startDownload(const QString &url);
    void saveFile();

private:
    Ui::MainWindow        *ui;
    QNetworkAccessManager  iNam;
    QString                iSaveFileName;
};

#endif // MAINWINDOW_H
