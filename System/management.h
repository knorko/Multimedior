#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <list>

#include <QObject>
#include <QQmlApplicationEngine>

#include "boid.h"


using namespace std;

class boid;
class Management : public QObject {

private:
    list<boid*> objList;

    Q_OBJECT
public:
    static QQmlApplicationEngine *engine;
    static QObject *canvas;

    explicit Management(QQmlApplicationEngine *mainEngine, QObject *canvasRoot);

    Q_INVOKABLE void init(uint count);
    Q_INVOKABLE void run();
};

#endif // MANAGEMENT_H
