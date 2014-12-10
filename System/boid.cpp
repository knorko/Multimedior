#include "boid.h"

boid::boid() {
    component = new QQmlComponent(Management::engine, QUrl(QStringLiteral("qrc:/Boid.qml")));
    if(component->status() == component->Ready) {
        object = component->create(Management::engine->rootContext());
        object->setProperty("parent", QVariant::fromValue(Management::canvas));
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
    }
    else
        qDebug() << component->errorString();
}

boid::~boid() {
    delete component;
    delete object;
}

void boid::Update() {
    // Logic goes here
    qDebug() << "Update";
}
