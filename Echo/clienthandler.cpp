#include "ClientHandler.h"
#include <QObject>
#include <QDebug>
#include <QtNetwork>

ClientHandler::ClientHandler(QObject *parent) : QObject(parent) { }

void ClientHandler::handleNewConnection()
{
    QTcpServer *server = qobject_cast<QTcpServer *>(sender());

    if ( server )
    {
        QTcpSocket *sock = server->nextPendingConnection();

        QObject::connect(sock, SIGNAL(readyRead()),
                         this, SLOT(handleReadyRead()));
    }

}

void ClientHandler::handleReadyRead()
{
    QTcpSocket *sock = qobject_cast<QTcpSocket *>(sender());
    QTextStream stream(sock);
    while ( ! stream.atEnd() )
    {
        QString line = stream.readLine();
        stream << line << endl;
    }
}

