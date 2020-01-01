#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <QObject>
#include <QTcpSocket>

class AppManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList availablePlaylists READ getMp_availablePlaylists NOTIFY availablePlaylistChanged)

public:
    enum AppState{
        HOME = 0,
        MUSIC,
        VIDEO,
    };
    Q_ENUM(AppState);

private :
    QTcpSocket* mp_socket;
    AppState m_appState;
    QStringList* mp_availablePlaylists;

public:
    explicit AppManager(QObject *parent = nullptr);
    ~AppManager();

    Q_INVOKABLE void launchApp(qint8 appstate);
    Q_INVOKABLE void connectTCP();
    Q_INVOKABLE bool writeTCP(QString message);
    void parseTCP(QString response);

    QStringList *getMp_availablePlaylists() const;

public slots:
    void receivedDataTCP();

signals:
    void availablePlaylistChanged();
};

#endif // APPMANAGER_H
