#include "vector2.h"

double x = 0;
double y = 0;

vector2::vector2(double x, double y) : x(x), y(y) {
}

vector2::~vector2() {
}

vector2 vector2::operator +(const vector2 &rhs) {
    return vector2(this->x + rhs.x, this->y + rhs.y);
}

vector2 vector2::operator -(const vector2 &rhs) {
    return vector2(this->x - rhs.x, this->y - rhs.y);
}

vector2 vector2::operator *(const double &scalar) {
    return vector2(this->x * scalar, this->y * scalar);
}

vector2 vector2::operator /(const double &scalar) {
    return vector2(this->x / scalar, this->y / scalar);
}

bool vector2::operator ==(const vector2 &rhs) {
    return (this->x == rhs.x) && (this->y == rhs.y);
}

bool vector2::operator !=(const vector2 &rhs) {
    return !(*this==rhs);
}



double vector2::getX() {
    return x;
}

double vector2::getY() {
    return y;
}

float vector2::getSqrMagnitude() {
    return x*x + y*y;
}

float vector2::getMagnitude() {
    return sqrt((x*x + y*y));
}
