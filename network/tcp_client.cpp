#include "tcp_client.h"

#include <chrono>



tcp_client::tcp_client(QObject *parent) : QObject(parent)
{
    initial("127.0.0.1",6000);

}

bool tcp_client::initial(QString ip, int port)
{
    socket_.connectToHost(ip,port);


    return true;
}

bool tcp_client::SendMsg(std::__cxx11::string str_)
{


    socket_.write(str_.c_str());

    return true;
}

bool tcp_client::SendMsg(int id, double x, double y, double z)
{
    QString qstr("Id:");

    qstr += QString::number(id,'g',12);

    qstr += " x: ";
    qstr += QString::number(x,'g',20);

    qstr += " y: ";
    qstr += QString::number(y,'g',20);

    qstr += " z: ";
    qstr += QString::number(z,'g',20);

    socket_.write(qstr.toStdString().c_str());

    return true;


}


