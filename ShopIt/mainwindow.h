#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class ShoppingItem;
class QListWidgetItem;

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
    void showAddItemDialog();
    void removeSelectedItem();
    void editItem(QListWidgetItem *item);

    void saveList();
    void loadList();

private:
    void addShoppingItem(ShoppingItem *item);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
