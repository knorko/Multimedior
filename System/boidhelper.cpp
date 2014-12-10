#include "boidhelper.h"

boidHelper::boidHelper() {

}

boidHelper::~boidHelper() {

}

double boidHelper::getX(){
    return object->property("x").value<double>();
}

void boidHelper::setX(double x) {
    object->setProperty("x", x);
}

double boidHelper::getY() {
    return object->property("y").value<double>();
}

void boidHelper::setY(double y) {
    object->setProperty("y", y);
}
