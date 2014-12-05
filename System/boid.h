#ifndef BOID_H
#define BOID_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>

#include "management.h"

class boid{
private:
    QObject *object;
    QQmlComponent *component;

public:
    boid();
    ~boid();

    void Update();
};

#endif // BOID_H
