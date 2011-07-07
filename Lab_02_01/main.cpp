#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;

    QVBoxLayout *outer = new QVBoxLayout(&w);
    QHBoxLayout *inner = new QHBoxLayout;

    QLineEdit *edit = new QLineEdit("Item Four");

    inner->addWidget(new QLabel("Item: "));
    inner->addWidget(edit);
    inner->addWidget(new QPushButton("Add"));

    QListWidget *list = new QListWidget;
    list->addItem("Item 1");
    list->addItem("Item 2");
    list->addItem("Item 3");

    outer->addLayout(inner);
    outer->addWidget(new QLabel("Item List"));
    outer->addWidget(list);

    w.show();

    app.exec();
    return 0;
}

