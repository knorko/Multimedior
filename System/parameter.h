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
    double canvasHeight = 592.0;
    /**
     * @brief Holds the width of the canvas object.
     */
    double canvasWidth = 772.0;
    /**
    * @brief Factor by which every boid movement is multiplied.
    */
    double speedFactor = 1.0;
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
    /**
     * @brief awarenessRadius
     */
    double awarenessRadius = 20.0;
    /**
     * @brief visualisation of the AwarenessRadius
     */
    bool visualizeAwarenessRadius = false;

    /**
     * @brief factor_flocking
     */
    double factor_flocking = 30.0;
    /**
     * @brief factor_avoidance
     */
    double factor_avoidance = 80.0;
    /**
     * @brief factor_match
     */
    double factor_match = 80.0;
    /**
     * @brief factor_target
     */
    double factor_target = 50.0;
    /**
     * @brief Main boid color
     */
    QColor mainColor = QColor(128, 255, 64);
    /**
     * @brief stores if boids follow/avoid the mouse
     */
    bool followMouse = true;

} Parameter;

#endif // DEFINE_H


