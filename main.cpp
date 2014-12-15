#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "System/management.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Create management object and register it as context property
    QObject *canvas = engine.rootObjects().first()->findChild<QObject*>("canvas");
    management *man = new management(&engine, canvas);
    engine.rootContext()->setContextProperty("management", man);

    return app.exec();
}
