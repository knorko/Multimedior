#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

/**
 * @brief Contains a two-dimensional vector and required arithmetic
 * operations.
 */
class vector2 {
private:
    /**
     * @brief The individual components.
     */
    double components[2];

    static float lerpFloat(float start, float end, float t);

public:
    vector2();
    vector2(double x, double y);
    ~vector2();

    vector2 operator +(const vector2 &rhs);
    vector2 operator -(const vector2 &rhs);
    vector2 operator *(const double &scalar);
    vector2 operator /(const double &scalar);
    vector2 operator =(const vector2 &rhs);
    vector2& operator +=(const vector2 &rhs);
    vector2& operator -=(const vector2 &rhs);
    vector2& operator *=(const double &scalar);
    vector2& operator /=(const double &scalar);
    bool operator ==(const vector2 &rhs);
    bool operator !=(const vector2 &rhs);

    const double* getPosition();
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    vector2 normalize();
    static vector2 lerp(vector2 start, vector2 end, float t);
    static vector2 lerpRotation(vector2 position, double lenght, vector2 target, float t);

    double getSqrMagnitude();
    double getMagnitude();
};

#endif // VECTOR2_H
