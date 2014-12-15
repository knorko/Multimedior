#include "management.h"

QQmlApplicationEngine *Management::engine = nullptr;
QObject *Management::canvas = nullptr;
list<boid*> Management::objList;

double Management::canvasHeight = 472;
double Management::canvasWidth = 612;
double Management::speed = 1;

Management::Management(QQmlApplicationEngine *mainEngine, QObject *canvasRoot) {
    engine = mainEngine;
    canvas = canvasRoot;
}

void Management::init(uint count) {
    // Populate the list with the desired amount of boids
    void (*operation)() = objList.size() < count ? &addBoid : &removeBoid;

    while(objList.size() != count)
        operation();
}

void Management::run() {
    foreach (boid *obj, objList) {
        obj->prepare();
        obj->Update();
        obj->finalize();
    }
}

void Management::clear() {
    // Clear the list entirely
    while(!objList.empty())
        removeBoid();
}

void Management::setCanvasHeight(double height) {
    canvasHeight = height;
}

void Management::setCanvasWidth(double width) {
    canvasWidth = width;
}

void Management::setSpeed(double newSpeed) {
    speed = newSpeed;
}

void Management::addBoid() {
    objList.push_back(new boid());
}

void Management::removeBoid() {
    delete objList.front();
    objList.pop_front();
}
