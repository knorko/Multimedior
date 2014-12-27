#include "boidhelper.h"
#include "management.h"


boidHelper::boidHelper() {
}

boidHelper::~boidHelper() {
}

/**
 * @brief Prepares required data
 *
 * This function is called before each boid has its boid::Update() function called.
 * It refreshes the position vector and calls the getNeighbors() function.
 */
void boidHelper::prepare() {
    position = vector2(getX(), getY());

    getNeighbors();
}

/**
 * @brief Applies changes to the boid
 *
 * This function is called after each boid had its boid::update() function called.
 * It sets the position depending on the velocity.
 */
void boidHelper::finalize() {
    // Set the position based on the velocity
    setX(getX() + velocity.getX() * management::speed);
    setY(getY() + velocity.getY() * management::speed);
}

/**
 * @brief Gets the current x position.
 *
 * The data originates from Qt and is the current x property of the boid object.
 *
 * @return Position on the x axis
 */
double boidHelper::getX() {
    return object->property("x").value<double>();
}

/**
 * @brief Gets the current y position.
 *
 * The data originates from Qt and is the current y property of the boid object.
 *
 * @return Position on the y axis
 */
double boidHelper::getY() {
    return object->property("y").value<double>();
}

/**
 * @brief Sets the position on the x axis.
 * @param x Desired x position
 */
void boidHelper::setX(double x) {
    object->setProperty("x", x);
}

/**
 * @brief Sets the position on the y axis.
 * @param y Desired y position
 */
void boidHelper::setY(double y) {
    object->setProperty("y", y);
}


/**
 * @brief Get the three closest neighbors for each boid
 *
 * This function builds a two-dimensional kd-tree from the current position of each
 * boid.
 * It then finds the three closest neighbors and saves them in a sorted order.
 *
 * The neighbors are stored in the boidHelper::neighbors array.
 */
void boidHelper::getNeighbors() {
    struct kdres *result;
    double position_neighbour[2];
    double sqrDistance;

    // Content: (x, y, squared distance)
    double nearest[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

    double position[2] = { getX(), getY() };
    result = kd_nearest_range(management::tree, position, management::canvasWidth);

    while(!kd_res_end(result)) {
        kd_res_item(result, position_neighbour);

        sqrDistance = sqrt(dist_sq(position, position_neighbour, 2));

        if(sqrDistance > 0) {
            double greatest = nearest[0][2];
            int greatestIndex = 0;

            for(int i = 0; i < 3; i++) {
                if(nearest[i][2] == 0) {
                    greatest = nearest[i][2];
                    greatestIndex = i;
                    break;
                }
                else if(greatest < nearest[i][2]) {
                    greatest = nearest[i][2];
                    greatestIndex = i;
                }
            }
            if(nearest[greatestIndex][2] > sqrDistance || nearest[greatestIndex][2] == 0) {
                nearest[greatestIndex][0] = position_neighbour[0];
                nearest[greatestIndex][1] = position_neighbour[1];
                nearest[greatestIndex][2] = sqrDistance;
            }
        }

        kd_res_next(result);
    }

    // Finally build the neighbor vectors and free the kd-tree
    for(int i=0; i<3; i++)
        neighbors[i] = vector2(nearest[i][0], nearest[i][1]);

    kd_res_free(result);
}

/**
 * @brief Calculate squared distance between two boids
 * @param a1 First vector
 * @param a2 Second vector
 * @param dims Dimensions of the vectors
 * @return Squared distance
 */
double boidHelper::dist_sq( double *a1, double *a2, int dims ) {
    double dist_sq = 0, diff;
    while( --dims >= 0 ) {
        diff = (a1[dims] - a2[dims]);
        dist_sq += diff*diff;
    }
    return dist_sq;
}
