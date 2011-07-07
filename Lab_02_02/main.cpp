#include <QtGui>
#include "colorselector.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;

    QVBoxLayout *outer = new QVBoxLayout(&w);
    QHBoxLayout *inner = new QHBoxLayout;

    QLabel *lblColor = new QLabel;
    QPushButton *btnStart = new QPushButton("Select Color");

    inner->addWidget(new QLabel("Color: "));
    inner->addWidget(lblColor);

    outer->addLayout(inner);
    outer->addWidget(btnStart);

    ColorSelector selector(*lblColor);
    QObject::connect(btnStart, SIGNAL(clicked()),
                     &selector, SLOT(showDialog()));


    w.show();

    app.exec();
    return 0;
}

