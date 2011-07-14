#include "labeledslider.h"
#include <QLabel>
#include <QSlider>
#include <QHBoxLayout>
#include <QDebug>

LabeledSlider::LabeledSlider(QWidget *parent) :
    QWidget(parent)
{
    QHBoxLayout *layout = new QHBoxLayout(this);
    iLabel  = new QLabel(this);
    iSlider = new QSlider(Qt::Horizontal, this);

    layout->addWidget(iSlider);
    layout->addWidget(iLabel);

    iLabel->setText(QString::number(iSlider->value()));

    QObject::connect(iSlider, SIGNAL(valueChanged(int)),
                     this, SLOT(setLabelFromNumber(int)));
}

void LabeledSlider::setLabelFromNumber(int num)
{
    iLabel->setText(QString::number(num));
    emit valueChanged(num);
}

void LabeledSlider::setValue(int newVal)
{
    if ( iSlider->value() != newVal )
    {
        iSlider->setValue(newVal);
    }
}

