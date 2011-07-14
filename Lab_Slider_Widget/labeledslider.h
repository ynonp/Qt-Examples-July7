#ifndef LABELEDSLIDER_H
#define LABELEDSLIDER_H

#include <QWidget>
class QSlider;
class QLabel;

class LabeledSlider : public QWidget
{
    Q_OBJECT
public:
    explicit LabeledSlider(QWidget *parent = 0);

signals:
    void valueChanged(int newVal);

public slots:
    void setValue(int newVal);

private slots:
    void setLabelFromNumber(int num);

private:
    QSlider *iSlider;
    QLabel  *iLabel;
};

#endif // LABELEDSLIDER_H
