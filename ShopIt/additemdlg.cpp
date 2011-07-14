#include "additemdlg.h"
#include "ui_additemdlg.h"
#include <qmath.h>
#include <QMessageBox>
#include <QDebug>

AddItemDlg::AddItemDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddItemDlg)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonBox, SIGNAL(accepted()),
                     this, SLOT(validate()));

    QObject::connect(ui->buttonBox, SIGNAL(rejected()),
                     this, SLOT(reject()));
}

AddItemDlg::~AddItemDlg()
{
    delete ui;
}

void AddItemDlg::validate()
{
    if ( ui->edtName->text().length() > 0 )
    {
        accept();
    }
    else
    {
        QMessageBox::warning(this,
                             tr("Missing Information"),
                             tr("Missing Item Name"),
                             QMessageBox::Ok);
    }
}

QString AddItemDlg::getName()
{
    return ui->edtName->text();
}

quint32 AddItemDlg::getPrice()
{
    // round the floating point number to a double
    return floor(ui->spnPrice->value()*100 + 0.5);
}

int AddItemDlg::getQty()
{
    return ui->spnQty->value();
}

void AddItemDlg::setItem(ShoppingItem item)
{
    double pd = (double) (item.getPrice() / 100.0);
    ui->spnPrice->setValue(pd);
    ui->spnQty->setValue(item.getQuantity());
    ui->edtName->setText(item.getName());
}

