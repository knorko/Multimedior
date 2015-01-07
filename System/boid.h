#ifndef BOID_H
#define BOID_H

#include "boidhelper.h"

/**
 * @brief The boid class contains all boid logic.
 *
 * Boids have certain behavior patterns. The first behavior is flocking. They strive towards
 * center of mass, of their neighbors. The second behavior is avoidance, which makes them
 * try to keep a certain distance to them. The next pattern is (velocity) matching. They adapt
 * their movement speed to speed of their neighbors. Further than that, the boids can either
 * strive towards or flee from a global goal (mouse), if one is set. On top of that, they're
 * pushed try to steer away from the borders of the canvas. The last behavior pattern is the
 * fleeing from every nearby #Predator.
 */
class Boid : public BoidHelper {
public:
    Boid();
    ~Boid();

    void update();
};

#endif // BOID_H
