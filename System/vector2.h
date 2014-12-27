#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

class vector2 {
private:
    double position[2];

public:
    vector2();
    vector2(double x, double y);
    ~vector2();

    vector2 operator +(const vector2 &rhs);
    vector2 operator -(const vector2 &rhs);
    vector2 operator *(const double &scalar);
    vector2 operator /(const double &scalar);
    vector2 operator =(const vector2 &rhs);
    bool operator ==(const vector2 &rhs);
    bool operator !=(const vector2 &rhs);

    const double* getPosition();
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);

    float getSqrMagnitude();
    float getMagnitude();
};

#endif // VECTOR2_H
