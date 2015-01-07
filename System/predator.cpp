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

    isPredator = true;

    velocity = Vector2(0.5,1);

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
    Vector2 v5 = Vector2();
//    Vector2 v1 = Vector2();
//    Vector2 v2 = Vector2();
//    Vector2 center = Vector2();

//    //IF Boid found then follow else random
//    for(int i = 0; i < 3; i++){
//        center = center + neighbours[i].position2;
//    }
//    center /= 3;

//    v1 = center - position;


//    Vector2 mp = getMousePosition();
//    if(mp != Vector2(0,0))
//        if((mp - position).getSqrMagnitude() > 10.0f)
//            v2 = mp-position;

//    velocity = Vector2::lerp(lastVel, velocity + v1 + v2, 0.016f);

//    lastVel = velocity;
    if(position.getX() < BORDER_THRESHOLD)
        v5.setX(1);
    else if(position.getX() >= getCanvasWidth() - BORDER_THRESHOLD)
        v5.setX(-1);

    if(position.getY() <  BORDER_THRESHOLD)
        v5.setY(1);
    else if(position.getY() >= getCanvasHeight() - BORDER_THRESHOLD){
        v5.setY(-1);
    }

    //Replace position with mouse position and look through the force-parameter with the mouse
    double powerx = 0.0;
    double powery = 0.0;

    if(position.getX() < BORDER_THRESHOLD)
        powerx = BORDER_THRESHOLD - position.getX();
    else if(position.getX() >= getCanvasWidth() - BORDER_THRESHOLD)
        powerx = BORDER_THRESHOLD + position.getX() - getCanvasWidth() ;
    else if(position.getY() < BORDER_THRESHOLD)
        powery = BORDER_THRESHOLD - position.getY();
    else if(position.getY() >= getCanvasHeight() - BORDER_THRESHOLD)
        powery = BORDER_THRESHOLD + position.getY() - getCanvasHeight();

    double force = 3.0 * (powerx + powery);

  velocity = velocity + v5.normalize() * force;
 }

