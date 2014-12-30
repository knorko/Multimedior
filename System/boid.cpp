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
boid::boid() {
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
}

boid::~boid() {
    delete component;
    delete object;
}

/**
 * @brief Boid logic
 */
void boid::Update() {
    // Logic goes here
    vector2 targetposition;
    for(int i=0; i<3; i++){
        if((neighbors[i] - position).getMagnitude()>60){
            targetposition = neighbors[i] - position;
            velocity = velocity + targetposition/targetposition.getMagnitude();
#ifdef BOID_DEBUG
            qDebug() << "attract";
#endif
        }
        else{
            targetposition = neighbors[i] - position;
            velocity = velocity - targetposition/targetposition.getMagnitude();
#ifdef BOID_DEBUG
            qDebug() << "avoid";
#endif
        }
    }
}
