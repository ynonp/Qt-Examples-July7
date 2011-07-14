#include <QApplication>
#include "labeledslider.h"
#include <QWidget>
#include <QLCDNumber>
#include <QVBoxLayout>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    QLCDNumber *num = new QLCDNumber;
    LabeledSlider *slider = new LabeledSlider;

    QVBoxLayout *layout = new QVBoxLayout(&w);
    layout->addWidget(slider);
    layout->addWidget(num);

    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     num, SLOT(display(int)));
    w.show();

    app.exec();
    return 0;
}

