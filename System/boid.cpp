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

    setX(50 + ((double)rand()/(double)(RAND_MAX)) * (Management::canvasWidth - 100));
    setY(50 + ((double)rand()/(double)(RAND_MAX)) * (Management::canvasHeight - 100));
}

boid::~boid() {
    delete component;
    delete object;
}

void boid::Update() {
    // Logic goes here
    qDebug() << "Update";
}
