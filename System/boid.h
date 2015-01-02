#ifndef BOID_H
#define BOID_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>

#include "boidhelper.h"

/**
 * @brief The boid class contains all boid logic.
 */
class boid : public boidHelper {
private:
    vector2 lastVel = vector2();

public:
    boid();
    ~boid();

    void Update();
};

#endif // BOID_H
