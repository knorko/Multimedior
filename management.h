#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include "boid.h"
#include "navigation.h"
#include <list>

class Management{

public:
    Management();
    Navigation nav;
    std::list<boid> L;

};

#endif // MANAGEMENT_H
