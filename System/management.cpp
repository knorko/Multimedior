#include "management.h"

QQmlApplicationEngine *Management::engine = nullptr;
QObject *Management::canvas = nullptr;
list<boid*> objList;

Management::Management(QQmlApplicationEngine *mainEngine, QObject *canvasRoot) {
    engine = mainEngine;
    canvas = canvasRoot;
}

void Management::init(uint count) {
    // Populate the list with the desired amount of boids
    if(objList.size() < count) {
        for(uint i=objList.size(); i<count; i++)
            objList.push_back(new boid());
    }
    else if(objList.size() > count) {
        for(uint i=objList.size(); i>count; i--) {
            delete objList.front();
            objList.pop_front();
        }
    }
}

void Management::run() {
    foreach (boid *obj, objList) {
        obj->Update();
    }
}
