#ifndef PREDATOR_H
#define PREDATOR_H

#include "boidhelper.h"

/**
 * @brief The Predator class contains the predator logic
 *
 * Predators sweep the area randomly, until they find a Boid, which they then pursue.
 */
class Predator : public BoidHelper {
public:
    Predator();
    ~Predator();

    void update();
};

#endif // PREDATOR_H
