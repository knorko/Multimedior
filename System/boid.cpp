#include "boid.h"

/**
 * @brief Create a new boid
 *
 * Creates a new QQmlComponent using the main QQmlApplicationEngine of the program and
 * the Boid.qml file.
 * After the component is created and ready, the QObject is created and parented to the
 * canvas object.
 * Lastly we set the position randomly, but staying within the boundaries.
 */
Boid::Boid() {
    component = new QQmlComponent(getEngine(), QUrl(QStringLiteral("qrc:/Boid.qml")));
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

Boid::~Boid() {
    delete component;
    delete object;
}

/**
 * @brief Boid logic
 */
void Boid::update(){
    Vector2 v1 = Vector2();
    Vector2 v2 = Vector2();
    Vector2 v3 = Vector2();
    Vector2 v4 = Vector2();
    Vector2 v5 = Vector2();
    Vector2 v6 = Vector2();
    Vector2 center = Vector2();

    // Rule1: move to local center of mass ( center becomes average of surrounding boids)
    for(int i = 0; i < 3; i++){
        center = center + neighbours[i].position2;
    }
    center /= 3;

    v1 = center - position;

    // Rule2: Avoidance : if distance to next boid smaller than threshold T boid changes course.
    center = Vector2();
    for(int i = 0; i < 3; i++){
        if ((neighbours[i].position2 - position).getSqrMagnitude() < (getSize() + 10.0) * (getSize() + 10.0)){
            center = center - (neighbours[i].position2 - position);
        }
    }
    v2 = center;

    // Rule3: Match velocity to surrounding Boids
    for(int i = 0; i < 3; i++){
        v3 = v3 + neighbours[i].velocity2;
    }
    v3 = v3/3;

    // Rule 4: Follow mouse position
    Vector2 mp = getMousePosition();
    if(!(mp == Vector2(0, 0))) {
        if((mp - position).getSqrMagnitude() > 7500)
            v4 = mp - position;
    }

    // Rule 5: Stray away from the boundaries


    if(position.getX() < 80)
        v5.setX(1);
    else if(position.getX() >= getCanvasWidth() - 80)
        v5.setX(-1);

    if(position.getY() <  80)
        v5.setY(1);
    else if(position.getY() >= getCanvasHeight() - 80){
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

    //Rule 6: Stay away from Predators
    double fleeingPower = 0.0;
    if(!(mp == Vector2(0, 0))) {
        double sqrDist = (mp - position).getSqrMagnitude();
        if(sqrDist > PREDATOR_THRESHOLD * PREDATOR_THRESHOLD) {
            v6 = position - mp;
            fleeingPower = sqrDist;
        }
    }


    velocity = Vector2::lerp(lastVel,
                             velocity + v1.normalize()*getFlockingFactor() + v2.normalize()*getAvoidanceFactor() +
                             v3.normalize()*getVelocityMatchFactor() + v4.normalize()*getTargetFactor() + v5 * force +
                             v6 * fleeingPower, 0.016f);

    lastVel = velocity;
}
