#ifndef BOIDHELPER_H
#define BOIDHELPER_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>
#include <QQmlApplicationEngine>

#include "vector2.h"
#include "kdtree.h"
#include "parameter.h"

/**
 * @brief The boidHelper class provides important functionaly that allows
 * the boids to be programmed.
 */
class BoidHelper {
private:
    /**
     * @brief Main QQmlApplicationEngine of the program.
     */
    static QQmlApplicationEngine *engine;
    /**
     * @brief QObject of the canvas.
     */
    static QObject *canvas;
    /**
     * @brief The kdtree used for neighbor search and collision.
     */
    static kdtree **tree;

    static Parameter *parameter;


    void getNeighbors();
    double dist_sq(double *a1, double *a2, int dims);

protected:
    /**
     * @brief The position of the boid.
     */
    Vector2 position;
    /**
     * @brief The velocity of the boid.
     */
    Vector2 velocity = Vector2(1, 0);
    Vector2 lastVel = Vector2();
    /**
     * @brief The three closest neighbors of the boid (sorted).
     */
    Vector2 neighbors[3];
    /**
     * @brief Search radius of the boids
     */
    double radius = 240;

    Vector2& getMousePosition() const;

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

    BoidHelper();
    ~BoidHelper();

    static void initialize(QQmlApplicationEngine *engine, QObject *canvas,kdtree **tree, Parameter *parameter);

    QQmlApplicationEngine *getEngine() const;
    QObject *getCanvas() const;
    double &getCanvasHeight() const;
    double &getCanvasWidth() const;

    void prepare();
    void finalize();

    double getX();
    double getY();
    void setX(double x);
    void setY(double y);

    void setSize(uint size);

    uint &getSize() const;
};

#endif // BOIDHELPER_H
