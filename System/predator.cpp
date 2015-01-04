#include "predator.h"

Predator::Predator() {
    component = new QQmlComponent(getEngine(), QUrl(QStringLiteral("qrc:/Predator.qml")));
    if(component->status() == component->Ready) {
        object = component->create(getEngine()->rootContext());
        object->setProperty("parent", QVariant::fromValue(getCanvas()));
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
    }
    else
        qDebug() << component->errorString();

    setY(50 + ((double)rand()/(double)(RAND_MAX)) * (getCanvasHeight() - 100));
    setX(50 + ((double)rand()/(double)(RAND_MAX)) * (getCanvasWidth() - 100));

    lastVel = vector2();
}

Predator::~Predator() {
    delete component;
    delete object;
}

void Predator::Update() {
    vector2 mp = getMousePosition();
    if(mp != vector2(0,0) && (mp - position).getSqrMagnitude() > 10.0f) {
        velocity = vector2::lerp(lastVel, mp - position, 0.016f);
    }
    else
        velocity = vector2();
}

