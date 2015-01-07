#ifndef BOIDHELPER_H
#define BOIDHELPER_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>
#include <QQmlApplicationEngine>

#include "vector2.h"
#include "kdtree.h"
#include "parameter.h"

#define BORDER_THRESHOLD 100.0
#define PREDATOR_THRESHOLD 10

/**
  * @brief The Neighbors struct stores the position and the velocity
  *
  * */
typedef struct Neighbors_s{
    /**
     * @brief Position of the neighbor
     */
    Vector2 position2;
    /**
     * @brief Velocity of the neighbor
     */
    Vector2 velocity2;

    bool isBoid = false;

} Neighbors;

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
    /**
     * @brief Holds pointers to certain parameters
     */
    static Parameter *parameters;

    /**
     * @brief gets Neighbours by range
     */
    void getNeighboursByRange();
    double dist_sq(double *a1, double *a2, int dims);
    /**
     * @brief sets the color
     */
    void setColor();
    /**
     * @brief sets the view radius
     */
    void setRadius();
    /**
     * @brief sets the visualization for the radius
     */
    void setRadiusVisualization();

protected:
    /**
     * @brief The position of the boid.
     */
    Vector2 position;
    /**
     * @brief The velocity of the boid.
     */
    Vector2 velocity = Vector2(1, 0);
    /**
     * @brief Stores the last known velocity
     */
    Vector2 lastVel = Vector2();
    /**
     * @brief The three closest neighbors of the boid (sorted).
     */
    Neighbors neighbours[3];

    Neighbors predator[3];

    bool isPredator = false;

    /**
     * @brief gets the current mouse position
     * @return Vector2&
     */
    Vector2& getMousePosition() const;
    /**
     * @brief getFlockingFactor
     * @return double
     */
    double getFlockingFactor() const;
    /**
     * @brief getAvoidanceFactor
     * @return double
     */
    double getAvoidanceFactor() const;
    /**
     * @brief getVelocityMatchFactor
     * @return double
     */
    double getVelocityMatchFactor() const;
    /**
     * @brief getTargetFactor
     * @return double
     */
    double getTargetFactor() const;

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

    static void initialize(QQmlApplicationEngine *engine, QObject *canvas,kdtree **tree, Parameter *parameters);

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
