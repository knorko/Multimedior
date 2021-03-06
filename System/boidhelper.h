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
#define PREDATOR_THRESHOLD 80.0
#define PREDATOR_ATTENUATION 20.0

/**
  * @brief The Neighbors struct stores the position and the velocity
  *
  * */
typedef struct Neighbors_s{
    /**
     * @brief Position of the neighbor
     */
    Vector2 pos;
    /**
     * @brief Velocity of the neighbor
     */
    Vector2 vel;
    /**
     * @brief boid or predator
     */
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


    void getNeighboursByRange();
    double dist_sq(double *a1, double *a2, int dims);
    void setColor();
    void setRadius();
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
    /**
     * @brief The three closest neighbors of the predator
     */
    Neighbors predator[3];
    /**
     * @brief boid or predator
     */
    bool isPredator = false;


    Vector2& getMousePosition() const;
    double getFlockingFactor() const;
    double getAvoidanceFactor() const;
    double getVelocityMatchFactor() const;
    double getTargetFactor() const;
    double getAwarenessRadius() const;
    bool followMouse() const;

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
