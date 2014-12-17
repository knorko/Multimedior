#include "boidhelper.h"
#include "management.h"

vector2 *velocity;

boidHelper::boidHelper() {
    velocity = new vector2(0, 0);
}

boidHelper::~boidHelper() {
    delete velocity;
}

// This is executed before each update
void boidHelper::prepare() {

}

// This is executed after each update
void boidHelper::finalize() {
    // Set the position based on the velocity
    setX(getX() + velocity->getX() * management::speed);
    setY(getY() + velocity->getY() * management::speed);

    // Stay within the boundaries
    double x = getX();
    if(x <= 0) {
        velocity->setX(-velocity->getX());
    }
    else if(x >= management::canvasWidth) {
        velocity->setX(-velocity->getX());
    }

    double y = getY();
    if(y <= 0) {
        velocity->setY(-velocity->getY());
    }
    else if(y >= management::canvasHeight) {
        velocity->setY(-velocity->getY());
    }
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
