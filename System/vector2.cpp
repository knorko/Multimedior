#include "vector2.h"


Vector2::Vector2() : Vector2(0, 0) {
}

/**
 * @brief Create new two-dimensional vector with given components.
 * @param x X component.
 * @param y Y component.
 */
Vector2::Vector2(double x, double y) {
    components[0] = x;
    components[1] = y;
}

Vector2::~Vector2() {
}

/**
 * @brief Helper function to interpolate two floats
 * @param start Starting float
 * @param end Target float
 * @param t Step size
 * @return start interpolated by one step
 */
float Vector2::lerpFloat(float start, float end, float t) {
    return start + t * (end - start);
}

/**
 * @brief Vector addition.
 * @param rhs The vector that is added.
 * @return Result of addition.
 */
Vector2 Vector2::operator +(const Vector2 &rhs) {
    return Vector2(this->components[0] + rhs.components[0], this->components[1] + rhs.components[1]);
}

/**
 * @brief Vector substraction.
 * @param rhs The vector that is substracted.
 * @return Result of substraction.
 */
Vector2 Vector2::operator -(const Vector2 &rhs) {
    return Vector2(this->components[0] - rhs.components[0], this->components[1] - rhs.components[1]);
}

/**
 * @brief Vector scaling.
 * @param scalar The scalar.
 * @return Result of scaling.
 */
Vector2 Vector2::operator *(const double &scalar) {
    return Vector2(this->components[0] * scalar, this->components[1] * scalar);
}

/**
 * @brief Vector scaling.
 * @param scalar The scalar.
 * @return Result of scaling.
 */
Vector2 Vector2::operator /(const double &scalar) {
    return Vector2(this->components[0] / scalar, this->components[1] / scalar);
}

/**
 * @brief Vector assignment.
 * @param rhs The source vector.
 * @return This, after components have been equated.
 */
Vector2 Vector2::operator =(const Vector2 &rhs) {
    components[0] = rhs.components[0];
    components[1] = rhs.components[1];
    return *this;
}

Vector2 &Vector2::operator +=(const Vector2 &rhs) {
    this->components[0] += rhs.components[0];
    this->components[1] += rhs.components[1];
    return *this;
}

Vector2 &Vector2::operator -=(const Vector2 &rhs) {
    this->components[0] -= rhs.components[0];
    this->components[1] -= rhs.components[1];
    return *this;
}

Vector2 &Vector2::operator *=(const double &scalar) {
    this->components[0] *= scalar;
    this->components[1] *= scalar;
    return *this;
}

Vector2 &Vector2::operator /=(const double &scalar) {
    this->components[0] /= scalar;
    this->components[1] /= scalar;
    return *this;
}

/**
 * @brief Vector comparison.
 *
 * True if all components are exactly equal.
 *
 * @param rhs The vector to compare to.
 * @return Result.
 */
bool Vector2::operator ==(const Vector2 &rhs) {
    return (this->components[0] == rhs.components[0]) && (this->components[1] == rhs.components[1]);
}

/**
 * @brief Vector comparison.
 *
 * True if not all components are exactly equal.
 *
 * @param rhs The vector to compare to.
 * @return Result.
 */
bool Vector2::operator !=(const Vector2 &rhs) {
    return !(*this==rhs);
}


/**
 * @brief Returns the vector in array form.
 * @return #components.
 */
const double *Vector2::getPosition() {
    return components;
}

/**
 * @brief Returns the x component of the vector.
 * @return #components[0].
 */
double Vector2::getX() {
    return components[0];
}

/**
 * @brief Returns the y component of the vector.
 * @return #components[1].
 */
double Vector2::getY() {
    return components[1];
}

/**
 * @brief Sets #components[0].
 * @param x X component
 */
void Vector2::setX(double x) {
    components[0] = x;
}

/**
 * @brief Sets #components[1].
 * @param y Y component.
 */
void Vector2::setY(double y) {
    components[1] = y;
}
/**
 * @brief Turns vector into unit vector
 * @return Normalized vector
 */
Vector2 Vector2::normalize() {
    return (*this = *this / (this->getMagnitude()));
}
/**
 * @brief Linear interpolation between two vectors
 *
 * Slowly interpolates between two vectors,
 * by interpolating the individual components
 *
 * @param start Starting vector
 * @param end Target vector
 * @param t Step size between 0 and 1
 * @return Vector after interpolation step
 */
Vector2 Vector2::lerp(Vector2 start, Vector2 end, float t) {
    return Vector2(lerpFloat(start.components[0], end.components[0], t),
            lerpFloat(start.components[1], end.components[1], t));
}
/**
 * @brief Rotates a vector towards another
 *
 * Like #lerp, but preserves magnitude by rotating it so it faces the target.
 *
 * @param start Starting vector
 * @param target Target vector
 * @param t Step size
 * @return Vector rotated towards the end, by one step
 */
Vector2 Vector2::lerpRotation(Vector2 start, Vector2 target, float t) {
    double angle = atan2(target.components[1] - start.components[1], target.components[0] - start.components[0]);
    angle = lerpFloat(angle, 0.0f, t);

    double ca = cos(angle);
    double sa = sin(angle);

    Vector2 result = Vector2(start.components[0] * ca - start.components[1] * sa, (start.components[0] * sa + start.components[1] * ca));
    return result.normalize() * start.getMagnitude();
}

/**
 * @return Squared magnitude of the vector.
 */
double Vector2::getSqrMagnitude() {
    return components[0]*components[0] + components[1]*components[1];
}

/**
 * @return Magnitude of the vector.
 */
double Vector2::getMagnitude() {
    return sqrt((components[0]*components[0] + components[1]*components[1]));
}
