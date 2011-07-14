#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    w.setStyleSheet("background-color: rgba(180, 60, 60, 80)");
    w.setAttribute(Qt::WA_TranslucentBackground);
    w.show();

    app.exec();
    return 0;
}

