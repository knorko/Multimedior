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
 * @brief Predator logic Calculate the Movement of Vectors relativ to Boids and set them accordingly.
 *
 * The Vectors are:
 * v1: Describes the closest boid and set their velocity according to their position.
 * v2: Describes the Velocity of other Boids nearby and matches it.
 * v3: Holds Information so that every Predator doesn't collide with the boundaries.
 */
void Predator::update() {
    Vector2 v1 = Vector2();
    Vector2 v2 = Vector2();
    Vector2 v3 = Vector2();
    Vector2 center = Vector2();

    center = center + neighbours[0].position2;

    v1 = center - position;

    // Rule3: Match velocity to surrounding Boids
    for(int i = 0; i < 3; i++){
        v2 = v2 + neighbours[i].velocity2;
    }
    v2 = (v2/3)*1.3;
    if(position.getX() < PREDATOR_ATTENUATION)
        v3.setX(1);
    else if(position.getX() >= getCanvasWidth() - PREDATOR_ATTENUATION)
        v3.setX(-1);

    if(position.getY() <  PREDATOR_ATTENUATION)
        v3.setY(1);
    else if(position.getY() >= getCanvasHeight() - PREDATOR_ATTENUATION)
        v3.setY(-1);


    //Replace position with mouse position and look through the force-parameter with the mouse
    double powerx = 0.0;
    double powery = 0.0;

    if(position.getX() < PREDATOR_ATTENUATION)
        powerx = PREDATOR_ATTENUATION - position.getX();
    else if(position.getX() >= getCanvasWidth() - PREDATOR_ATTENUATION)
        powerx = PREDATOR_ATTENUATION + position.getX() - getCanvasWidth() ;
    else if(position.getY() < PREDATOR_ATTENUATION)
        powery = PREDATOR_ATTENUATION - position.getY();
    else if(position.getY() >= getCanvasHeight() - PREDATOR_ATTENUATION)
        powery = PREDATOR_ATTENUATION + position.getY() - getCanvasHeight();

    double force = 3.0 * (powerx + powery);

  velocity = Vector2::lerp(lastVel, velocity + v1.normalize() * 1.3 + v2.normalize() * 1.3 + v3.normalize() * force, 0.016f);

  lastVel = velocity;
 }

