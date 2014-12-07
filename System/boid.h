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

    double getX();
    void setX(double value);
    double getY();
    void setY(double value);

public:
    boid();
    ~boid();

    void Update();
};

#endif // BOID_H
