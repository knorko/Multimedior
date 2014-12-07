#include "management.h"

QQmlApplicationEngine *Management::engine = nullptr;
QObject *Management::canvas = nullptr;
list<boid*> Management::objList;

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
    foreach (boid *obj, objList)
        obj->Update();
}

void Management::clear() {
    // Clear the list entirely
    while(!objList.empty())
        removeBoid();
}

void Management::addBoid() {
    objList.push_back(new boid());
}

void Management::removeBoid() {
    delete objList.front();
    objList.pop_front();
}
