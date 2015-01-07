#ifndef BOID_H
#define BOID_H

#include "boidhelper.h"

#define BORDER_THRESHOLD 200.0
#define PREDATOR_THRESHOLD 50.0

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
