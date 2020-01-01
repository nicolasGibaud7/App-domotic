#include "appmanager.h"
#include <QDebug>
#include <QTextCodec>

AppManager::AppManager(QObject *parent) : QObject(parent)
{
    mp_socket = new QTcpSocket();
    connect(mp_socket, &QIODevice::readyRead, this, &AppManager::receivedDataTCP);
    connectTCP();
}

AppManager::~AppManager()
{
    delete mp_socket;
}

void AppManager::launchApp(QString appName)
{
    writeTCP(appName);
}

void AppManager::connectTCP()
{
    mp_socket->connectToHost("192.168.1.19", 10000);
}

bool AppManager::writeTCP(QString message)
{
        qDebug()<<__FUNCTION__<<message;

        if(mp_socket->state() == QAbstractSocket::ConnectedState){
            QByteArray ba = message.toLocal8Bit();
            mp_socket->write(ba.data(), message.length());
            return 1;
        }
        else{
            qDebug()<<"socket not connected, current state :"<<mp_socket->state();
            connectTCP();
            return 0;
        }
}

void AppManager::receivedDataTCP()
{
    uint size = mp_socket->bytesAvailable();
    QByteArray ba = mp_socket->readAll();
    QString s = QTextCodec::codecForMib(1015)->toUnicode(ba);


    qDebug()<<"New message of"<<size<<"received :["<<ba<<"]";
}

