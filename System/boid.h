#ifndef BOID_H
#define BOID_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>

#include "boidhelper.h"
#include "management.h"

class management;
class boid : public boidHelper {

public:
    boid();
    ~boid();

    void Update();
};

#endif // BOID_H
