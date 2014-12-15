#ifndef BOIDHELPER_H
#define BOIDHELPER_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>

#include "vector2.h"

class boidHelper {
protected:
    vector2 *velocity;

public:
    QObject *object;
    QQmlComponent *component;

    boidHelper();
    ~boidHelper();

    void prepare();
    void finalize();

    double getX();
    void setX(double x);
    double getY();
    void setY(double y);
};

#endif // BOIDHELPER_H
