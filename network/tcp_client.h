#ifndef TCP_CLIENT_H
#define TCP_CLIENT_H

#include <QObject>

#include <QtNetwork>
#include <QNetworkInterface>

#include <queue>

class tcp_client : public QObject
{
    Q_OBJECT
public:
    explicit tcp_client(QObject *parent = 0);

    /*
     *initial network configure.
     *
     */
    bool initial(QString ip,int port);

    bool SendMsg(std::string str_);

    bool SendMsg(int id,double x,double y,double z);

protected:
    QTcpSocket socket_;//socket

    QString ip_addr_;//ip address for server

    int port_;//port of server

    std::queue<std::string> msg_que_;//msg que,

signals:

public slots:
};

#endif // TCP_CLIENT_H
