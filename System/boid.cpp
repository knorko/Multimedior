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
    Vector2 center = position;

    // Rule1: move to local center of mass ( center becomes average of surrounding boids)
    Vector2 lc = Vector2();
    for(int i = 0; i < 3; i++){
        lc = lc + neighbours[i].position2;
    }
    lc = lc / 3;

    v1 = lc - position;

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
        if(!(mp == Vector2(0, 0)))
            if((mp - position).getSqrMagnitude() > 7500)
            v4 = mp - position;

    velocity = Vector2::lerp(lastVel,
                             velocity + v1*(1/getFlockingFactor()) + v2*(1/getAvoidanceFactor()) + v3*(1/getVelocityMatchFactor()) + v4*(1/getTargetFactor()),
                             0.016f);

    lastVel = velocity;
}
