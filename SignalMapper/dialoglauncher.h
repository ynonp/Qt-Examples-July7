#ifndef DIALOGLAUNCHER_H
#define DIALOGLAUNCHER_H

#include <QObject>
class Dialog;

class DialogLauncher : public QObject
{
    Q_OBJECT
public:
    explicit DialogLauncher(QObject *parent = 0);

signals:

public slots:
    void startModalDialog();
    void startModeless();

private:
    Dialog *d;
};

#endif // DIALOGLAUNCHER_H
