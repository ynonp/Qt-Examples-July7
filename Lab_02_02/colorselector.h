#ifndef COLORSELECTOR_H
#define COLORSELECTOR_H

#include <QObject>
#include <QLabel>

class ColorSelector : public QObject
{
    Q_OBJECT
public:
    explicit ColorSelector(QLabel &lblTarget,
                           QObject *parent = 0);

signals:

public slots:
    void setColor(QColor &clr);
    void showDialog();

private:
    QLabel &iLblTarget;
};

#endif // COLORSELECTOR_H
