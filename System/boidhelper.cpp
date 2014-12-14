#include "boidhelper.h"

boidHelper::boidHelper() {
    velocity[0] = 0;
    velocity[1] = 0;
}

boidHelper::~boidHelper() {

}

// This is executed before each update
void boidHelper::prepare() {

}

// This is executed after each update
void boidHelper::finalize() {
    // Set the position based on the velocity
    setX(getX() + velocity[0]);
    setY(getY() + velocity[1]);
}

double boidHelper::getX() {
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
