#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QTcpSocket>

class AppManager : public QObject
{
    Q_OBJECT
private :
    QTcpSocket* mp_socket;
public:
    explicit AppManager(QObject *parent = nullptr);
    ~AppManager();

    Q_INVOKABLE void launchApp(QString appName);
    Q_INVOKABLE void connectTCP();
    Q_INVOKABLE bool writeTCP(QString message);

public slots:
    void receivedDataTCP();

signals:

};

#endif // APPMANAGER_H
