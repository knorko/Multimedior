#ifndef PREDATOR_H
#define PREDATOR_H

#include "boidhelper.h"

/**
 * @brief The Predator class contains the predator logic
 *
 * Predators sweep the area randomly until they find a #Boid, which they then pursue.
 * Besides that, they match their velocity to the velocity of surrounding boids. Lastly
 * they steer away from the boundaries.
 */
class Predator : public BoidHelper {
public:
    Predator();
    ~Predator();

    void update();
};

#endif // PREDATOR_H
