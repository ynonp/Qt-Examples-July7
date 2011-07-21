#include "dialoglauncher.h"
#include "dialog.h"
#include <QDebug>

DialogLauncher::DialogLauncher(QObject *parent) :
    QObject(parent)
{
    d = new Dialog();
}

void DialogLauncher::startModalDialog()
{
    Dialog d;

    int ok = d.exec();
    qDebug() << ok;
}

void DialogLauncher::startModeless()
{
    d->show();
    d->raise();
    d->activateWindow();
}

