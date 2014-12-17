#include "management.h"

QQmlApplicationEngine *management::engine = nullptr;
QObject *management::canvas = nullptr;
vector<boid*> management::objList;

double management::canvasHeight = 472;
double management::canvasWidth = 612;
double management::speed = 1;

management::management(QQmlApplicationEngine *mainEngine, QObject *canvasRoot) {
    engine = mainEngine;
    canvas = canvasRoot;
}

void management::init(uint count, uint size) {
    // Populate the list with the desired amount of boids
    void (*operation)() = objList.size() < count ? &addBoid : &removeBoid;

    while(objList.size() != count)
        operation();

    // Set the desire size
    boidHelper::initialize(size);
    foreach (boid *obj, objList) {
        obj->setSize(size);
    }
}

void management::run() {
    foreach (boid *obj, objList) {
        obj->prepare();
        obj->Update();
        obj->finalize();
    }
}

void management::clear() {
    // Clear the list entirely
    while(!objList.empty())
        removeBoid();
}

void management::setCanvasHeight(double height) {
    canvasHeight = height;
}

void management::setCanvasWidth(double width) {
    canvasWidth = width;
}

void management::setSpeed(double newSpeed) {
    speed = newSpeed;
}

void management::addBoid() {
    objList.push_back(new boid());
}

void management::removeBoid() {
    delete objList.back();
    objList.pop_back();
}
