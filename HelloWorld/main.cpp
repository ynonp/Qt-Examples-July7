#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QPushButton btn("Hello World");
    btn.show();

    app.exec();

    return 0;
}

