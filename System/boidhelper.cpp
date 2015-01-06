#include "boidhelper.h"


QQmlApplicationEngine *BoidHelper::engine = nullptr;
QObject *BoidHelper::canvas = nullptr;
kdtree **BoidHelper::tree = nullptr;
Parameter *BoidHelper::parameters = nullptr;

BoidHelper::BoidHelper() {
}

BoidHelper::~BoidHelper() {
}


/**
 * @brief Initialize the BoidHelper class
 *
 * The BoidHelper contains essential functions that are required to program the
 * boids.
 * This function gives it the necessary access to certain GUI parameters. It only
 * has effect one time. Once the values have been set, future calls will have no effect.
 *
 * @param engine The main QQmlApplicationEngine the application uses.
 * @param canvas The QObject that holds the canvas we want the boids to move on.
 * @param tree Pointer towards the later used kd-tree.
 * @param parameter Pointer towards the parameter struct.
 */
void BoidHelper::initialize(QQmlApplicationEngine *engine, QObject *canvas, kdtree **tree, Parameter *parameter) {
    if(!BoidHelper::engine && !BoidHelper::canvas) {

        BoidHelper::engine = engine;
        BoidHelper::canvas = canvas;
        BoidHelper::parameters = parameter;
        BoidHelper::tree = tree;
    }
    else {
      qDebug() << "boidHelper already initialized!";
    }
}

/**
 * @return Main QQmlApplicationEngine.
 */
QQmlApplicationEngine *BoidHelper::getEngine() const {
    return BoidHelper::engine;
}

/**
 * @return Canvas QObject.
 */
QObject *BoidHelper::getCanvas() const {
    return BoidHelper::canvas;
}

/**
 * @return Height of the canvas.
 */
double &BoidHelper::getCanvasHeight() const {
    return parameters->canvasHeight;
}

/**
 * @return Width of the canvas.
 */
double &BoidHelper::getCanvasWidth() const {
    return parameters->canvasWidth;
}

/**
 * @brief Prepares required data
 *
 * This function is called before each boid has its boid::Update() function called.
 * It refreshes the position vector and calls the getNeighbors() function.
 */
void BoidHelper::prepare() {
    position = Vector2(getX(), getY());
    setSize(parameters->size);
    setColor();

    getNeighbors();
}

/**
 * @brief Applies changes to the boid
 *
 * This function is called after each boid had its boid::update() function called.
 * It sets the position depending on the velocity.
 */
void BoidHelper::finalize() {
    // Clamp the speed
    if(velocity != Vector2(0, 0)) {
        velocity.normalize();
        velocity *= parameters->velocity_max + (((double)rand()/(double)(RAND_MAX)));
    }

    // Set the position based on the velocity
    setX(getX() + velocity.getX() * parameters->speedFactor);
    setY(getY() + velocity.getY() * parameters->speedFactor);

    // Stay within the boundaries
    double x = getX();
    if(x <= 0) {
        setX(0);
        velocity.setX(-velocity.getX());
    }
    else if(x >= getCanvasWidth() - parameters->size) {
        setX(getCanvasWidth() - parameters->size);
        velocity.setX(-velocity.getX());
    }

    double y = getY();
    if(y <= 0) {
        setY(0);
        velocity.setY(-velocity.getY());
    }
    else if(y >= getCanvasHeight() - parameters->size) {
        setY(getCanvasHeight() - parameters->size);
        velocity.setY(-velocity.getY());
    }
}

/**
 * @brief Gets the current x position.
 *
 * The data originates from Qt and is the current x property of the boid object.
 *
 * @return Position on the x axis
 */
double BoidHelper::getX() {
    return object->property("x").value<double>();
}

/**
 * @brief Gets the current y position.
 *
 * The data originates from Qt and is the current y property of the boid object.
 *
 * @return Position on the y axis
 */
double BoidHelper::getY() {
    return object->property("y").value<double>();
}

/**
 * @brief Sets the position on the x axis.
 * @param x Desired x position
 */
void BoidHelper::setX(double x) {
    object->setProperty("x", x);
}

/**
 * @brief Sets the position on the y axis.
 * @param y Desired y position
 */
void BoidHelper::setY(double y) {
    object->setProperty("y", y);
}

/**
 * @brief Set the boid size.
 * @param size Desired size
 */
void BoidHelper::setSize(uint size) {
    object->setProperty("height", size);
    object->setProperty("width", size);
}

/**
 * @return Boid size.
 */
uint &BoidHelper::getSize() const{
    return parameters->size;
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

void BoidHelper::getNeighbors() {
    struct kdres *result;
    double position_neighbour[2];
    double sqrDistance;

    // Content: (x, y, squared distance, velocity.X, velocity.Y)
    double nearest[3][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    double position[2] = { getX(), getY() };
    result = kd_nearest_range(*tree, position, parameters->canvasWidth);

    while(!kd_res_end(result)) {
       BoidHelper *b = (BoidHelper*) kd_res_item(result, position_neighbour);

        sqrDistance = sqrt(dist_sq(position, position_neighbour, 2));

        if(sqrDistance > 0) {
            double greatest = nearest[0][2];
            int greatestIndex = 0;

            for(int i = 0; i < 3; i++) {
                if(nearest[i][2] == 0) {
                    greatest = nearest[i][2];
                    greatestIndex = i;
                    nearest[i][4] = b->velocity.getY();
                    nearest[i][3] = b->velocity.getX();
                    break;
                }
                else if(greatest < nearest[i][2]) {
                    greatest = nearest[i][2];
                    nearest[i][3] = b->velocity.getX();
                    nearest[i][4] = b->velocity.getY();
                    greatestIndex = i;
                }
            }
            if(nearest[greatestIndex][2] > sqrDistance || nearest[greatestIndex][2] == 0) {
                nearest[greatestIndex][0] = position_neighbour[0];
                nearest[greatestIndex][1] = position_neighbour[1];
                nearest[greatestIndex][2] = sqrDistance;
                nearest[greatestIndex][3] = b->velocity.getX();
                nearest[greatestIndex][4] = b->velocity.getY();
            }
        }

        kd_res_next(result);
    }

    // Finally build the neighbor vectors and free the kd-tree
    for(int i=0; i<3; i++){
        neighbours[i].position2 = Vector2(nearest[i][0], nearest[i][1]);
        neighbours[i].velocity2 = Vector2(nearest[i][3], nearest[i][4]);
    }
    kd_res_free(result);
}

/**
 * @brief Calculate squared distance between two boids
 * @param a1 First vector
 * @param a2 Second vector
 * @param dims Dimensions of the vectors
 * @return Squared distance
 */
double BoidHelper::dist_sq( double *a1, double *a2, int dims ) {
    double dist_sq = 0, diff;
    while( --dims >= 0 ) {
        diff = (a1[dims] - a2[dims]);
        dist_sq += diff*diff;
    }
    return dist_sq;
}

void BoidHelper::setColor() {
    object->setProperty("color", parameters->mainColor);
}

/**
 * @return Current mouse position
 */
Vector2 &BoidHelper::getMousePosition() const {
    return parameters->mousePosition;
}
