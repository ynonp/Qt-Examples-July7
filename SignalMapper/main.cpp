#include <QtGui>
#include "dialog.h"
#include <QDebug>
#include "dialoglauncher.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.show();

    QLCDNumber *display = new QLCDNumber(&w);

    QHBoxLayout *btnsLayout = new QHBoxLayout();
    QVBoxLayout *layout     = new QVBoxLayout();

    layout->addWidget(display);
    layout->addLayout(btnsLayout);

////////////////////////////////////

    QSignalMapper *mapper = new QSignalMapper(&w);
    QObject::connect(mapper, SIGNAL(mapped(QString)),
                     display, SLOT(display(QString)));

    for ( int i=0; i < 3; ++i)
    {
        QPushButton *b = new QPushButton(QString("Button: %1").arg(i));
        btnsLayout->addWidget(b);

        QObject::connect(b, SIGNAL(clicked()),
                         mapper, SLOT(map()));
        mapper->setMapping(b, QString("%1").arg(i));
    }

    w.setLayout(layout);
    w.resize(120, 120);


    QPushButton *startDialog = new QPushButton("Modal");
    QPushButton *modeless = new QPushButton("Modeless");

    DialogLauncher launcher;

    QObject::connect(startDialog, SIGNAL(clicked()),
                     &launcher, SLOT(startModalDialog()));

    QObject::connect(modeless, SIGNAL(clicked()),
                     &launcher, SLOT(startModeless()));

    layout->addWidget(startDialog);
    layout->addWidget(modeless);

    app.exec();
}
