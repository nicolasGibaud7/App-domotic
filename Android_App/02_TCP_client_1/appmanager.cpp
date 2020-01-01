#include "appmanager.h"
#include <QDebug>
#include <QTextCodec>

QStringList *AppManager::getMp_availablePlaylists() const
{
    return mp_availablePlaylists;
}

AppManager::AppManager(QObject *parent) : QObject(parent)
{
    mp_socket = new QTcpSocket();
    mp_availablePlaylists = new QStringList();
    m_appState = HOME;

    connect(mp_socket, &QIODevice::readyRead, this, &AppManager::receivedDataTCP);
    connectTCP();
}

AppManager::~AppManager()
{
    mp_socket->disconnectFromHost();
    delete mp_socket;
}

void AppManager::launchApp(qint8 appstate)
{
    m_appState = static_cast<AppState>(appstate);

    writeTCP(QString::number(appstate));
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

void AppManager::parseTCP(QString response)
{
    switch (m_appState) {
    case HOME:
        qDebug()<<"No response supported in HOME state";
        break;
    case MUSIC:
        mp_availablePlaylists->clear();
        mp_availablePlaylists->append(response.split(";"));

        emit availablePlaylistChanged();
        break;
    case VIDEO:
        qDebug()<<"No response supported in VIDEO state";
        break;
    default:
        break;
    }
}

void AppManager::receivedDataTCP()
{
    QByteArray ba = mp_socket->readAll();
    QString s(ba);

    qDebug()<<"New message:["<<s<<"]";

    parseTCP(s);
}

