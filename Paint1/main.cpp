#include "myrect.h"
#include <QApplication>
#include "artisticwidget.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);


    ArtisticWidget w;
    w.show();

    return app.exec();
}

