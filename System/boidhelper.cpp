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
    getNeighbours();
}

// This is executed after each update
void boidHelper::finalize() {
    // Set the position based on the velocity
    setX(getX() + velocity->getX() * management::speed);
    setY(getY() + velocity->getY() * management::speed);
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



int boidHelper::getNeighbours() {

    struct kdres *result;
    double position_neighbour[2];
    double distance;

    double position[2] = { getX(), getY()};
    result = kd_nearest_range(management::tree, position, radius);

    qDebug() << "Found: " << kd_res_size(result);

    while(!kd_res_end(result)) {
        kd_res_item(result, position_neighbour);

        distance = sqrt(dist_sq(position, position_neighbour, 2));

        if(distance > 0)
            qDebug() << "Boid at" << position_neighbour[0] << "," << position_neighbour[1] << "is " << distance << "away";

        kd_res_next(result);
    }

    kd_res_free(result);
    return 0;
}

double boidHelper::dist_sq( double *a1, double *a2, int dims ) {
    double dist_sq = 0, diff;
    while( --dims >= 0 ) {
        diff = (a1[dims] - a2[dims]);
        dist_sq += diff*diff;
    }
    return dist_sq;
}
