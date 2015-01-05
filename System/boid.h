#ifndef BOID_H
#define BOID_H

#include "boidhelper.h"

/**
 * @brief The boid class contains all boid logic.
 */
class Boid : public BoidHelper {
public:
    Boid();
    ~Boid();

    void update();
};

#endif // BOID_H
