#ifndef BOID_H
#define BOID_H

#include "boidhelper.h"

/**
 * @brief The boid class contains all boid logic.
 */
class boid : public boidHelper {
public:
    boid();
    ~boid();

    void Update();
};

#endif // BOID_H
