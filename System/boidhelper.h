#ifndef BOIDHELPER_H
#define BOIDHELPER_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>

#include "vector2.h"

class boidHelper {
protected:
    vector2 *velocity;
    static double size;

public:
    QObject *object;
    QQmlComponent *component;

    boidHelper();
    ~boidHelper();

    static void initialize(uint size);

    void prepare();
    void finalize();

    double getX();
    void setX(double x);
    double getY();
    void setY(double y);

    void setSize(uint size);

    const double& getSize();
};

#endif // BOIDHELPER_H
