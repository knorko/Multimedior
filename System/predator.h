#ifndef PREDATOR_H
#define PREDATOR_H

#include "boidhelper.h"

class Predator : public BoidHelper {
public:
    Predator();
    ~Predator();

    void update();
};

#endif // PREDATOR_H
