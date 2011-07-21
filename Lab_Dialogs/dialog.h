#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(int val, QWidget *parent = 0);
    ~Dialog();

    int value();
private slots:
    void validate();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
