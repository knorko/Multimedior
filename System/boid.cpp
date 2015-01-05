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
    vector2 v4(getCanvasWidth()/2 , getCanvasHeight()/2);
    vector2 center= v4;

    //Rule1: move to local center of mass ( center becomes average of surrounding boids)
    for(int i = 0; i < 3; i++){
        center = center + neighbours[i].position2;
//        //Rule2: Avoidance : if distance to next boid smaller than threshold T boid changes course.
//        if ((neighbours[i].position2 - position).getSqrMagnitude()<100){
//            center = center - (neighbours[i].position2 - position);
//        }
            qDebug() << "center: "<< center.getX()<<" "<<center.getY()<<" Neighbour: "<<neighbours[i].position2.getX() <<" "<<neighbours[i].position2.getY();
    }
    center = center / 3;
    v1 = center - position;

    //Rule2: Avoidance : if distance to next boid smaller than threshold T boid changes course.
    center = center - center;
    for(int i = 0; i < 3; i++){
        if ((neighbours[i].position2 - position).getSqrMagnitude()<1000){
            center = center - (neighbours[i].position2 - position);
        }
    }
    v2 = center;
    //Rule3: Match velocity to surrounding Boids
    for(int i = 0; i < 3; i++){
        v3 = v3 + neighbours[i].velocity2;
    }
    v3 = v3/3;
    v3 = (v3 - position)/4;
    velocity = velocity + v1 + v2 + v3;


}
