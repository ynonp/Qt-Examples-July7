#include <QObject>

int main(int argc, char **argv)
{
    QObject o1;

    QObject *o2 = new QObject(o1);
    QObject *o3 = new QObject(o1);


    return 0;
}

