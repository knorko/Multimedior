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

    lastVel = Vector2();
}

Predator::~Predator() {
    delete component;
    delete object;
}

/**
 * @brief Predator logic
 */
void Predator::update() {
    Vector2 v1 = Vector2();
    Vector2 v2 = Vector2();
    Vector2 center = Vector2();

    //IF Boid found then follow else random
    for(int i = 0; i < 3; i++){
        if((position - neighbours[i].position2).getMagnitude() < position.getMagnitude() * radius && neighbours[i].isBoid)
            center = neighbours[i].position2;
    }

    v1 = center - position;


    Vector2 mp = getMousePosition();
    if(mp != Vector2(0,0))
        if((mp - position).getSqrMagnitude() > 10.0f)
            v2 = mp-position;

    velocity = Vector2::lerp(lastVel, velocity + v1 + v2, 0.016f);

    lastVel = velocity;
 }

