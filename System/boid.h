#ifndef BOID_H
#define BOID_H

#include "coordinate.h"

class boid{
private:
    const int count = 500;
    Coordinate c;

public:
    boid();

    void fixedUpdate();
    void Update();
};

#endif // BOID_H
