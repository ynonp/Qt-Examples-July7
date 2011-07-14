#ifndef ADDITEMDLG_H
#define ADDITEMDLG_H

#include <QDialog>
#include "shoppingitem.h"

namespace Ui {
    class AddItemDlg;
}

class AddItemDlg : public QDialog
{
    Q_OBJECT

public:
    explicit AddItemDlg(QWidget *parent = 0);
    ~AddItemDlg();

    QString getName();
    quint32 getPrice();
    int     getQty();

    void setItem(ShoppingItem item);

private slots:
    void validate();

private:
    Ui::AddItemDlg *ui;
};

#endif // ADDITEMDLG_H
