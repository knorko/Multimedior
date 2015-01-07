#ifndef BOID_H
#define BOID_H

#include "boidhelper.h"

/**
 * @brief The boid class contains all boid logic.
 *
 * Boids have certain behavior patterns. They flock, while avoiding getting to close
 * to each other, they flee, when a Predator gets too close and (optionally) follow a
 * global target.
 */
class Boid : public BoidHelper {
public:
    Boid();
    ~Boid();

    void update();
};

#endif // BOID_H
