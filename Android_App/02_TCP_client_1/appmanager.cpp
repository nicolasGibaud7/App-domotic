#include "appmanager.h"
#include <QDebug>

AppManager::AppManager(QObject *parent) : QObject(parent)
{
    mp_socket = new QTcpSocket();
}

AppManager::~AppManager()
{
    delete mp_socket;
}

void AppManager::launchApp(QString message)
{
    qDebug()<<__FUNCTION__<<message;

    if(mp_socket->state() == QAbstractSocket::ConnectedState){
        QByteArray ba = message.toLocal8Bit();
        mp_socket->write(ba.data(), message.length());
    }
    else{
        qDebug()<<"socket not connected, current state :"<<mp_socket->state();
    }
}

void AppManager::connectTCP()
{
    mp_socket->connectToHost("192.168.1.19", 10000);
}

