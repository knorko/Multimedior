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
void Boid::update() {
    Vector2 targetposition;
    Vector2 result;
    for(int i=0; i<3; i++){
        if((neighbors[i] - position).getSqrMagnitude()>3600){
            targetposition = neighbors[i] - position;
            result = result + targetposition/targetposition.getMagnitude();
#ifdef BOID_DEBUG
            qDebug() << "attract";
#endif
        }
        else{
            targetposition = neighbors[i] - position;
            result = result - targetposition/targetposition.getMagnitude();
#ifdef BOID_DEBUG
            qDebug() << "avoid";
#endif
        }
    }
    velocity = result;
    Vector2 mp = getMousePosition();
    if(!(mp == Vector2(0, 0))) {
        if((position - mp).getSqrMagnitude() > 10)
        velocity = Vector2::lerp(lastVel, result * 50 + (mp - position), 0.016f);
    }
    else
        velocity = Vector2::lerp(lastVel, result, 0.016f * 10);

    lastVel = velocity;
}
