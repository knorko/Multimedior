#ifndef NAVIGATION_H
#define NAVIGATION_H

#include "boid.h"

class Navigation{
private:
    double speed;
    float proximity;
    //Only 3-4 neigbhors visible all time
    boid *neigbhor;
    //Field of View(distance-limited)
    //Distance-Squared / Distance-cubed weighting function

    //DONT FOLLOW A Leader
    //NO flock center knowledge

public:
    Navigation();

    float calculateProximity();
    double calculateSpeed();
    void detectCollison();
    void setDirection(float iSpeed, float iProx);

};

#endif // NAVIGATION_H
