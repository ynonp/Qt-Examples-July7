#include <QtCore>
#include <QtNetwork>
#include "ClientHandler.h"

int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    QTcpServer server;
    ClientHandler client(NULL);

    server.listen(QHostAddress::Any, 7900);
    QObject::connect(&server, SIGNAL(newConnection()),
                     &client, SLOT(handleNewConnection()));
    app.exec();

    return 0;
}
