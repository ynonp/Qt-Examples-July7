#include "myrect.h"
#include <QPainter>
#include <QDebug>

MyRect::MyRect(QWidget *parent) :
    QWidget(parent)
{
}

void MyRect::paintEvent(QPaintEvent *)
{
    qDebug() << "Paint !";
    QPainter painter(this);

    QPen pen = painter.pen();
    pen.setWidth(10);

    QColor bgColor = palette().color(QPalette::Window);
//    QColor bgColor = Qt::red;
    pen.setBrush(QBrush(bgColor));

    QColor kool(0, 0, 0, 200);
    painter.setPen(pen);
    painter.setBrush(kool);

    painter.drawRect(0, 0, rect().width(), rect().height());
}
