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

    // Randomize staring velocity to sweep
    velocity.setX(2.0 + ((double)rand()/(double)(RAND_MAX)) * -4.0);
    velocity.setY(2.0 + ((double)rand()/(double)(RAND_MAX)) * -4.0);

    lastVel = velocity;
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
    double forceX = 0.0;
    double forceY = 0.0;
    double force;

    Vector2 v1 = Vector2();
    Vector2 v2 = Vector2();
    Vector2 v3 = Vector2();
    Vector2 center = Vector2();

    //Rule1: Hunt the nearest Boid
    center += neighbours[0].pos;

    if(center != Vector2())
        v1 = center - position;

    // Rule2: Match velocity to surrounding Boids
    for(int i = 0; i < 3; i++){
        v2 = v2 + neighbours[i].vel;
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

    if(position.getX() < PREDATOR_ATTENUATION)
        forceX = PREDATOR_ATTENUATION - position.getX();
    else if(position.getX() >= getCanvasWidth() - PREDATOR_ATTENUATION)
        forceX = PREDATOR_ATTENUATION + position.getX() - getCanvasWidth() ;
    else if(position.getY() < PREDATOR_ATTENUATION)
        forceY = PREDATOR_ATTENUATION - position.getY();
    else if(position.getY() >= getCanvasHeight() - PREDATOR_ATTENUATION)
        forceY = PREDATOR_ATTENUATION + position.getY() - getCanvasHeight();

    force = 3.0 * (forceX + forceY);

  velocity = Vector2::lerp(lastVel, velocity + v1.normalize() * 1.3 + v2.normalize() * 1.3 + v3.normalize() * force, 0.128f);

  lastVel = velocity;
 }

