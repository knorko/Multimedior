#include "management.h"



vector<Boid*> Management::objList;
vector<Predator*> Management::predList;
kdtree *Management::tree = nullptr;

Parameter parameters;


/**
 * @brief Initialize the boidHelper class.
 *
 * Calls boidHelper::initialize with all required data.
 *
 * @param engine Main QQmlApplicationEngine of the application.
 * @param canvas QObject of the canvas.
 */
Management::Management(QQmlApplicationEngine *engine, QObject *canvas) {
    BoidHelper::initialize(engine, canvas, &tree, &parameters);
}

/**
 * @brief Set amount of desired boids.
 *
 * Delete or create boids until #objList holds the desired amount of references.
 *
 * @param count Desired amount of boids.
 * @param size The desired size for the boids.
 */
void Management::init(uint count, uint size) {
    void (*operation)() = objList.size() < count ? &addBoid : &removeBoid;

    while(objList.size() != count)
        operation();

    predList.push_back(new Predator());

    // Set the desire size
    parameters.size = size;
    foreach (Boid *obj, objList) {
        obj->setSize(size);
    }

    foreach (Predator *obj, predList) {
        obj->setSize(size);
    }
}

/**
 * @brief Run the boid update routine
 *
 * First the kd-tree is prepared, then all boids have their boid::prepare(), boid::Update()
 * and boid::finalize() functions called (in that order).
 *
 * Afterwards we clear and free the kd-tree.
 */
void Management::run() {
    prepareTree();

    foreach (Predator *obj, predList) {
        obj->prepare();
        obj->update();
        obj->finalize();
    }

    foreach (Boid *obj, objList) {
        obj->prepare();
        obj->update();
        obj->finalize();
    }
    kd_clear(tree);
    kd_free(tree);
}

/**
 * @brief Delete all boids.
 *
 * Each boid is deleted until #objList is empty.
 */
void Management::clear() {
    while(!objList.empty())
        removeBoid();
    while(!predList.empty()) {
        delete predList.back();
        predList.pop_back();
    }
}

/**
 * @brief Update #canvasHeight.
 *
 * The actual height of the canvas is stored in a variable instead of being
 * retrieved from the UI every time.
 *
 * @param height Current canvas height.
 */
void Management::setCanvasHeight(double height) {
    parameters.canvasHeight = height;
}

/**
 * @brief Update #canvasWidth.
 *
 * The actual width of the canvas is stored in a variable instead of being
 * retrieved from the UI every time.
 *
 * @param width Current canvas width.
 */
void Management::setCanvasWidth(double width) {
    parameters.canvasWidth = width;
}

/**
 * @brief Update speed factor.
 *
 * #speedFactor is set by the QML code and contains the factor by which every
 * boid movement is multiplied.
 *
 * @param speed Current speed factor.
 */
void Management::setSpeed(double speed) {
    parameters.speedFactor = speed;
}

/**
 * @brief Set the velocity and variance.
 * @param average Average velocity.
 * @param variance Variance.
 */
void Management::setVelocity(double average, double variance) {
    parameters.velocity_var = variance;
    parameters.velocity_avg = average;
}

void Management::setMousePosition(double x, double y) {
parameters.mousePosition.setX(x);
parameters.mousePosition.setY(y);
}

/**
 * @brief Add a new boid to #objList.
 */
void Management::addBoid() {
    objList.push_back(new Boid());
}

/**
 * @brief Remove a boid from #objList.
 */
void Management::removeBoid() {
    delete objList.back();
    objList.pop_back();
}

void Management::prepareTree() {
    tree = kd_create(2);

    foreach (Boid *obj, objList) {
        double position[2] = { obj->getX(), obj->getY()};
        kd_insert( tree, position, 0);
    }
}
