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

    Q_INVOKABLE void launchApp(QString message);
    Q_INVOKABLE void connectTCP();

signals:

};

#endif // APPMANAGER_H
