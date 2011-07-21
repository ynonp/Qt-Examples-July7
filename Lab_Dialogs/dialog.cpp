#include "dialog.h"
#include "ui_dialog.h"
#include <QMessageBox>

Dialog::Dialog(int val, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonBox, SIGNAL(rejected()),
                     this, SLOT(reject()));

    QObject::connect(ui->buttonBox, SIGNAL(accepted()),
                     this, SLOT(validate()));

    ui->spinBox->setValue(val);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::validate()
{
    int val = value();

    if ( val < 50 )
    {
        accept();
        return;
    }
    else
    {
        QMessageBox::warning(this, tr("Value too high"),
                             tr("Please type a value < 50"));

    }
}

int Dialog::value()
{
    return ui->spinBox->value();
}

