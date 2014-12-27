#ifndef BOIDHELPER_H
#define BOIDHELPER_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>

#include "vector2.h"
#include "kdtree.h"

class boidHelper {
private:
    double radius = 240;

    void getNeighbors();
    double dist_sq(double *a1, double *a2, int dims);

protected:
    /**
     * @brief The position of the boid.
     */
    vector2 position;

    /**
     * @brief The velocity of the boid.
     */
    vector2 velocity;

    /**
     * @brief The three closest neighbors of the boid (sorted).
     */
    vector2 neighbors[3];

public:
    /**
     * @brief The gui object of this boid.
     *
     * This is parented to the the render canvas of the UI.
     */
    QObject *object;

    /**
     * @brief The gui component of this boid.
     */
    QQmlComponent *component;

    boidHelper();
    ~boidHelper();

    void prepare();
    void finalize();

    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
};

#endif // BOIDHELPER_H
