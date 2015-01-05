#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>

#include <QObject>
#include <QQmlApplicationEngine>

#include "boid.h"
#include "predator.h"
#include "kdtree.h"
#include "parameter.h"

using namespace std;

/**
 * @brief The management class brigdes the gap between the UI
 * and the main logic.
 */
class Management : public QObject {

private:
    /**
     * @brief vector of boid pointers.
     *
     * This is used to iterate over all the boids and call their respective
     * Boid::update functions.
     */
    static vector<Boid*> boidList;
    /**
     * @brief vector of predator pointers.
     *
     * This is used to iterate over all the predators and call their respective
     * Predator::update functions.
     */
    static vector<Predator*> predList;
    /**
     * @brief Two-dimensional kd-tree that holds the boids.
     *
     * This is used for finding the n nearest neighbors efficiently so that
     * flocking, avoidance and collision detection can be realized in an
     * efficient manner
     */
    static kdtree *tree;

    static void addBoid();
    static void removeBoid();
    static void addPredator();
    static void removePredator();

    void prepareTree();

    Q_OBJECT
public:

    explicit Management(QQmlApplicationEngine *engine, QObject *canvas);

    Q_INVOKABLE void init(uint boidCount, uint predatorCount);
    Q_INVOKABLE void run();
    Q_INVOKABLE void clear();
    Q_INVOKABLE void setCanvasHeight(double height);
    Q_INVOKABLE void setCanvasWidth(double width);
    Q_INVOKABLE void setSpeed(double speedFactor);
    Q_INVOKABLE void setVelocity(double average, double variance);
    Q_INVOKABLE void setMousePosition(double x, double y);
    Q_INVOKABLE void setSize(uint size);
};

#endif // MANAGEMENT_H
