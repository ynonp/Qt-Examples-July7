#ifndef __CLIENT_HANDLER_H
#define __CLIENT_HANDLER_H

#include <QObject>
#include <QAbstractSocket>

class ClientHandler : public QObject
{
    Q_OBJECT

    public:
        explicit ClientHandler(QObject *parent);

    private slots:
        void handleNewConnection();
        void handleReadyRead();
};

#endif
