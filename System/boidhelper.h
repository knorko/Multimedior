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

    int getNeighbours();

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

    double dist_sq(double *a1, double *a2, int dims);
};

#endif // BOIDHELPER_H
