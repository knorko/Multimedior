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

    lastVel = vector2();
}

boid::~boid() {
    delete component;
    delete object;
}

/**
 * @brief Boid logic
 */
//void boid::Update() {
//    vector2 targetposition;
//    vector2 result;
//    for(int i=0; i<3; i++){
//        if((neighbors[i] - position).getSqrMagnitude()>3600){
//            targetposition = neighbors[i] - position;
//            result = result + targetposition/targetposition.getMagnitude();
//#ifdef BOID_DEBUG
//            qDebug() << "attract";
//#endif
//        }
//        else{
//            targetposition = neighbors[i] - position;
//            result = result - targetposition/targetposition.getMagnitude();
//#ifdef BOID_DEBUG
//            qDebug() << "avoid";
//#endif
//        }
//    }
//    velocity = result;
//    vector2 mp = getMousePosition();
//    if(!(mp == vector2(0, 0))) {
//        if((position - mp).getSqrMagnitude() > 10)
//        velocity = vector2::lerp(lastVel, result * 50 + (mp - position), 0.016f);
//    }
//    else
//        velocity = vector2::lerp(lastVel, result, 0.016f * 10);

//    lastVel = velocity;
//}
//TODO: PARAMETRISE NUMBER OF BOIDS
void boid::Update(){
    vector2 v1;
    vector2 v2;
    vector2 v3;
    vector2 v4;
    vector2 center = position;

    //Rule1: move to local center of mass ( center becomes average of surrounding boids)
    vector2 lc = vector2();
    for(int i = 0; i < 3; i++){
        lc = lc + neighbours[i].position2;
    }
    lc = lc / 3;

    v1 = lc - position;

    //Rule2: Avoidance : if distance to next boid smaller than threshold T boid changes course.
    center = vector2();
    for(int i = 0; i < 3; i++){
        if ((neighbours[i].position2 - position).getSqrMagnitude()<getSize() * getSize()){
            center = center - (neighbours[i].position2 - position);
        }
    }
    v2 = center;
    lastVel = v2;
    //Rule3: Match velocity to surrounding Boids
    for(int i = 0; i < 3; i++){
        v3 = v3 + neighbours[i].velocity2;
    }
    v3 = v3/3;
    //v3 = (v3 - position)/4;
    vector2 mp = getMousePosition();
        if(!(mp == vector2(0, 0)))
            if((mp - position).getSqrMagnitude() > 7500)
            v4 = mp - position;

    velocity = velocity + v1/100 + v2*50 + v3/50 + v4/2500;

}
