#include <QtGui>
#include "clicker.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton btn("Click ME !");
    Clicker clicker;

    QObject::connect(
                &btn, SIGNAL(clicked()),
                &clicker, SLOT(doSomething()));
    btn.show();

    app.exec();
    return 0;
}

