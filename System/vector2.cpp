#include "vector2.h"

float vector2::lerpFloat(float start, float end, float t) {
    return start + t * (end - start);
}

vector2::vector2() : vector2(0, 0) {
}

/**
 * @brief Create new two-dimensional vector with given components.
 * @param x X component.
 * @param y Y component.
 */
vector2::vector2(double x, double y) {
    components[0] = x;
    components[1] = y;
}

vector2::~vector2() {
}

/**
 * @brief Vector addition.
 * @param rhs The vector that is added.
 * @return Result of addition.
 */
vector2 vector2::operator +(const vector2 &rhs) {
    return vector2(this->components[0] + rhs.components[0], this->components[1] + rhs.components[1]);
}

/**
 * @brief Vector substraction.
 * @param rhs The vector that is substracted.
 * @return Result of substraction.
 */
vector2 vector2::operator -(const vector2 &rhs) {
    return vector2(this->components[0] - rhs.components[0], this->components[1] - rhs.components[1]);
}

/**
 * @brief Vector scaling.
 * @param scalar The scalar.
 * @return Result of scaling.
 */
vector2 vector2::operator *(const double &scalar) {
    return vector2(this->components[0] * scalar, this->components[1] * scalar);
}

/**
 * @brief Vector scaling.
 * @param scalar The scalar.
 * @return Result of scaling.
 */
vector2 vector2::operator /(const double &scalar) {
    return vector2(this->components[0] / scalar, this->components[1] / scalar);
}

/**
 * @brief Vector assignment.
 * @param rhs The source vector.
 * @return This, after components have been equated.
 */
vector2 vector2::operator =(const vector2 &rhs) {
    components[0] = rhs.components[0];
    components[1] = rhs.components[1];
    return *this;
}

vector2 &vector2::operator +=(const vector2 &rhs) {
    this->components[0] += rhs.components[0];
    this->components[1] += rhs.components[1];
    return *this;
}

vector2 &vector2::operator -=(const vector2 &rhs) {
    this->components[0] -= rhs.components[0];
    this->components[1] -= rhs.components[1];
    return *this;
}

vector2 &vector2::operator *=(const double &scalar) {
    this->components[0] *= scalar;
    this->components[1] *= scalar;
    return *this;
}

vector2 &vector2::operator /=(const double &scalar) {
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
bool vector2::operator ==(const vector2 &rhs) {
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
bool vector2::operator !=(const vector2 &rhs) {
    return !(*this==rhs);
}


/**
 * @brief Returns the vector in array form.
 * @return #components.
 */
const double *vector2::getPosition() {
    return components;
}

/**
 * @brief Returns the x component of the vector.
 * @return #components[0].
 */
double vector2::getX() {
    return components[0];
}

/**
 * @brief Returns the y component of the vector.
 * @return #components[1].
 */
double vector2::getY() {
    return components[1];
}

/**
 * @brief Sets #components[0].
 * @param x X component
 */
void vector2::setX(double x) {
    components[0] = x;
}

/**
 * @brief Sets #components[1].
 * @param y Y component.
 */
void vector2::setY(double y) {
    components[1] = y;
}

vector2 vector2::normalize() {
    return (*this = *this / (this->getMagnitude()));
}

vector2 vector2::lerp(vector2 start, vector2 end, float t) {
    return vector2(lerpFloat(start.components[0], end.components[0], t),
            lerpFloat(start.components[1], end.components[1], t));
}

vector2 vector2::lerpRotation(vector2 position, double lenght, vector2 target, float t) {
    double angle = atan2(target.components[1] - position.components[1], target.components[0] - position.components[0]);
    angle = lerpFloat(angle, 0.0f, t);

    double ca = cos(angle);
    double sa = sin(angle);

    vector2 result = vector2(position.components[0] * ca - position.components[1] * sa, (position.components[0] * sa + position.components[1] * ca));
    return result.normalize() * lenght;
}

/**
 * @return Squared magnitude of the vector.
 */
double vector2::getSqrMagnitude() {
    return components[0]*components[0] + components[1]*components[1];
}

/**
 * @return Magnitude of the vector.
 */
double vector2::getMagnitude() {
    return sqrt((components[0]*components[0] + components[1]*components[1]));
}
