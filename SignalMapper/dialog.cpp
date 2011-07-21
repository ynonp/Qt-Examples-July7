#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    QObject::connect(ui->buttonBox, SIGNAL(accepted()),
                     this, SLOT(accept()));

    QObject::connect(ui->buttonBox, SIGNAL(rejected()),
                     this, SLOT(reject()));
}

Dialog::~Dialog()
{
    delete ui;
}
