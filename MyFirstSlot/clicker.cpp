#include "clicker.h"
#include <QDebug>

Clicker::Clicker(QObject *parent) :
    QObject(parent)
{
}


void Clicker::doSomething()
{
    qDebug() << "Ouch ! that hurt...";
}

