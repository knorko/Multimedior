#ifndef DEFINE_H
#define DEFINE_H
#include "vector2.h"
#include "QColor"


/**
 * @brief Parameter_S includes all parameter variables.
 */
typedef struct Parameter_S{
    /**
     * @brief Holds the height of the canvas object.
     */
    double canvasHeight = 592;
    /**
     * @brief Holds the width of the canvas object.
     */
    double canvasWidth = 772;
    /**
    * @brief Factor by which every boid movement is multiplied.
    */
    double speedFactor = 1;
    /**
     * @brief Boid size.
     */
    uint size = 7;
    /**
     * @brief Maximal movement velocity of the boids.
     */
    double velocity_max = 1.5;
    /**
     * @brief Mouse Position.
     */
    Vector2 mousePosition = Vector2();

    double factor_flocking = 30.0;
    double factor_avoidance = 80.0;
    double factor_match = 80.0;
    double factor_target = 50.0;
    QColor mainColor = QColor(128, 255, 64);

} Parameter;

#endif // DEFINE_H


