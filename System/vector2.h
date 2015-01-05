#ifndef VECTOR2_H
#define VECTOR2_H

#include <cmath>

/**
 * @brief Contains a two-dimensional vector and required arithmetic
 * operations.
 */
class Vector2 {
private:
    /**
     * @brief The individual components.
     */
    double components[2];

    static float lerpFloat(float start, float end, float t);

public:
    Vector2();
    Vector2(double x, double y);
    ~Vector2();

    Vector2 operator +(const Vector2 &rhs);
    Vector2 operator -(const Vector2 &rhs);
    Vector2 operator *(const double &scalar);
    Vector2 operator /(const double &scalar);
    Vector2 operator =(const Vector2 &rhs);
    Vector2& operator +=(const Vector2 &rhs);
    Vector2& operator -=(const Vector2 &rhs);
    Vector2& operator *=(const double &scalar);
    Vector2& operator /=(const double &scalar);
    bool operator ==(const Vector2 &rhs);
    bool operator !=(const Vector2 &rhs);

    const double* getPosition();
    double getX();
    double getY();
    void setX(double x);
    void setY(double y);
    Vector2 normalize();
    static Vector2 lerp(Vector2 start, Vector2 end, float t);
    static Vector2 lerpRotation(Vector2 position, double lenght, Vector2 target, float t);

    double getSqrMagnitude();
    double getMagnitude();
};

#endif // VECTOR2_H
