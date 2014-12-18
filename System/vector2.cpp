#include "vector2.h"

double position[2];

vector2::vector2(double x, double y) {
    position[0] = x;
    position[1] = y;
}

vector2::~vector2() {
}

vector2 vector2::operator +(const vector2 &rhs) {
    return vector2(this->position[0] + rhs.position[0], this->position[1] + rhs.position[1]);
}

vector2 vector2::operator -(const vector2 &rhs) {
    return vector2(this->position[0] - rhs.position[0], this->position[1] - rhs.position[1]);
}

vector2 vector2::operator *(const double &scalar) {
    return vector2(this->position[0] * scalar, this->position[1] * scalar);
}

vector2 vector2::operator /(const double &scalar) {
    return vector2(this->position[0] / scalar, this->position[1] / scalar);
}

vector2 vector2::operator =(const vector2 &rhs) {
    position[0] = rhs.position[0];
    position[1] = rhs.position[1];
    return *this;
}

bool vector2::operator ==(const vector2 &rhs) {
    return (this->position[0] == rhs.position[0]) && (this->position[1] == rhs.position[1]);
}

bool vector2::operator !=(const vector2 &rhs) {
    return !(*this==rhs);
}



const double *vector2::getPosition() {
    return position;
}

double vector2::getX() {
    return position[0];
}

double vector2::getY() {
    return position[1];
}

void vector2::setX(double x) {
    position[0] = x;
}

void vector2::setY(double y) {
    position[1] = y;
}

float vector2::getSqrMagnitude() {
    return position[0]*position[0] + position[1]*position[1];
}

float vector2::getMagnitude() {
    return sqrt((position[0]*position[0] + position[1]*position[1]));
}
