#include "boid.h"

boid::boid() {
    component = new QQmlComponent(Management::engine, QUrl(QStringLiteral("qrc:/Boid.qml")));
    if(component->status() == component->Ready) {
        object = component->create(Management::engine->rootContext());
        object->setProperty("parent", QVariant::fromValue(Management::canvas));
        QQmlEngine::setObjectOwnership(object, QQmlEngine::CppOwnership);
    }
    else
        qDebug() << component->errorString();
}

boid::~boid() {
    delete component;
    delete object;
}

void boid::Update() {
    // Logic goes here
    qDebug() << "Update";
}

// Returns the current x coordinate of the boid
double boid::getX() {
    return object->property("x").value<double>();
}

// Sets the current x coordinate
void boid::setX(double value) {
    object->setProperty("x", value);
}

// Returns the current y coordinate of the boid
double boid::getY() {
    return object->property("y").value<double>();
}

// Sets the current y coordinate
void boid::setY(double value) {
    object->setProperty("y", value);
}
