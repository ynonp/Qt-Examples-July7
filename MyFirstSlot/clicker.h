#ifndef CLICKER_H
#define CLICKER_H

#include <QObject>

class Clicker : public QObject
{
    Q_OBJECT
public:
    explicit Clicker(QObject *parent = 0);

signals:

public slots:
    void doSomething();
};

#endif // CLICKER_H
