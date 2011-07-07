#include "colorselector.h"
#include <QColorDialog>

ColorSelector::ColorSelector(QLabel &lblTarget,
                             QObject *parent) :
    QObject(parent),
    iLblTarget(lblTarget)
{
}


void ColorSelector::setColor(QColor &clr)
{
    iLblTarget.setText(clr.name());
}

void ColorSelector::showDialog()
{
    QColor selected = QColorDialog::getColor();
    QString style = QString("background-color: %1").arg(selected.name());
    iLblTarget.setText(selected.name());
    iLblTarget.setStyleSheet(style);
}

