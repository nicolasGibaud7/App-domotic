#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "appmanager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    AppManager* appManager = new AppManager();

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("AppManager", appManager);
    qmlRegisterType<AppManager>("StateEnum",1,0,"AppState");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
