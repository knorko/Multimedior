#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include <vector>

#include <QObject>
#include <QQmlApplicationEngine>

#include "boid.h"
#include "kdtree.h"

using namespace std;

class boid;
class management : public QObject {

private:
    static vector<boid*> objList;

    static void addBoid();
    static void removeBoid();

    void prepareTree();

    Q_OBJECT
public:
    static QQmlApplicationEngine *engine;
    static QObject *canvas;
    static double canvasHeight;
    static double canvasWidth;
    static double speed;
    static kdtree *tree;

    explicit management(QQmlApplicationEngine *mainEngine, QObject *canvasRoot);

    Q_INVOKABLE void init(uint count);
    Q_INVOKABLE void run();
    Q_INVOKABLE void clear();
    Q_INVOKABLE void setCanvasHeight(double height);
    Q_INVOKABLE void setCanvasWidth(double width);
    Q_INVOKABLE void setSpeed(double newSpeed);
};

#endif // MANAGEMENT_H
