#ifndef PREDATOR_H
#define PREDATOR_H

#include "boidhelper.h"

class Predator : public boidHelper {
public:
    Predator();
    ~Predator();

    void Update();
};

#endif // PREDATOR_H
