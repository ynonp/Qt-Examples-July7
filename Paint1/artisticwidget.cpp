#include "artisticwidget.h"
#include <QPaintEvent>
#include <QPainter>

ArtisticWidget::ArtisticWidget(QWidget *parent) :
    QWidget(parent)
{
}

void ArtisticWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p(this);

    QList<QColor> colors;
    colors << Qt::red << Qt::blue << Qt::green << Qt::yellow << Qt::magenta;

    qreal width = rect().width();
    qreal height = rect().height();

    p.save();
    p.restore();

    for ( int i=0; i < width; i += 10 )
    {
        int colorIdx = (i / 10) % colors.length();
        p.setBrush(QBrush(colors.at(colorIdx)));

        p.rotate((width - i) / 10);
        p.drawRect(0, 0, width - i, height - i);
    }
}
