#include "management.h"

QQmlApplicationEngine *management::engine = nullptr;
QObject *management::canvas = nullptr;
vector<boid*> management::objList;
kdtree *management::tree = nullptr;

double management::canvasHeight = 472;
double management::canvasWidth = 612;
double management::speed = 0.01;

management::management(QQmlApplicationEngine *mainEngine, QObject *canvasRoot) {
    engine = mainEngine;
    canvas = canvasRoot;
}

void management::init(uint count) {
    // Populate the list with the desired amount of boids
    void (*operation)() = objList.size() < count ? &addBoid : &removeBoid;

    while(objList.size() != count)
        operation();
}

void management::run() {
    prepareTree();

    foreach (boid *obj, objList) {
        obj->prepare();
        obj->Update();
        obj->finalize();
    }
    kd_clear(tree);
    kd_free(tree);
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

void management::prepareTree() {
    tree = kd_create(2);

    foreach (boid *obj, objList) {
        double position[2] = { obj->getX(), obj->getY()};
        kd_insert( tree, position, 0);
    }
}
