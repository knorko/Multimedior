#include "management.h"

QQmlApplicationEngine *Management::engine = nullptr;
QObject *Management::canvas = nullptr;
list<boid*> objList;

Management::Management(QQmlApplicationEngine *mainEngine, QObject *canvasRoot) {
    engine = mainEngine;
    canvas = canvasRoot;
}

void Management::init(int count) {
    // Populate the list with the desired amount of boids
}

void Management::run() {
    foreach (boid *obj, objList) {
        obj->Update();
    }
}
