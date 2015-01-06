#ifndef DEFINE_H
#define DEFINE_H
#include "vector2.h"


/**
 * @brief Parameter_S includes all parameter variables.
 */
typedef struct Parameter_S{
    /**
     * @brief Holds the height of the canvas object.
     */
    double canvasHeight = 472;
    /**
     * @brief Holds the width of the canvas object.
     */
    double canvasWidth = 612;
    /**
    * @brief Factor by which every boid movement is multiplied.
    */
    double speedFactor = 1;
    /**
     * @brief Boid size.
     */
    uint size = 10;
    /**
     * @brief Average movement velocity of the boids.
     */
    double velocity_avg = 1;
    /**
     * @brief Mouse Position.
     */
    Vector2 mousePosition = Vector2();

    double factor_flocking = 100.0;
    double factor_avoidance = 20.0;
    double factor_match = 50.0;
    double factor_target = 25.0;

} Parameter;

#endif // DEFINE_H


