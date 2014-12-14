#ifndef BOIDHELPER_H
#define BOIDHELPER_H

#include <QDebug>
#include <QObject>
#include <QQmlComponent>

class boidHelper {
protected:
    double velocity[2];

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
