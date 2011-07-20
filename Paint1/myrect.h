#ifndef MYRECT_H
#define MYRECT_H

#include <QWidget>


class MyRect : public QWidget
{
    Q_OBJECT
public:
    explicit MyRect(QWidget *parent = 0);

    virtual void paintEvent(QPaintEvent *);

};

#endif // MYRECT_H
