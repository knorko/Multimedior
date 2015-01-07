#include <ctime>

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "System/management.h"

int main(int argc, char *argv[]) {
    srand((unsigned)time(NULL));

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    // Create management object and register it as context property
    Management *man = new Management();
    engine.rootContext()->setContextProperty("management", man);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *canvas = engine.rootObjects().first()->findChild<QObject*>("canvas");
    man->initialize(&engine, canvas);

    return app.exec();
}
