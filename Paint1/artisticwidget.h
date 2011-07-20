#ifndef ARTISTICWIDGET_H
#define ARTISTICWIDGET_H

#include <QWidget>

class ArtisticWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ArtisticWidget(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);

};

#endif
