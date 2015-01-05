#include "management.h"

vector<Boid*> Management::boidList;
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
 * @brief Set amount of desired boids and predators.
 *
 * Delete or create boids and predators until #boidList and #predList hold the desired amount of references.
 *
 * @param boidCount Desired amount of boids.
 * @param predatorCount Desired amount of predators.
 */
void Management::init(uint boidCount, uint predatorCount) {
    void (*boidOp)() = boidList.size() < boidCount ? &addBoid : &removeBoid;
    void (*predOp)() = predList.size() < predatorCount ? &addPredator : &removePredator;

    while(boidList.size() != boidCount)
        boidOp();
    while(predList.size() != predatorCount)
        predOp();
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

    foreach (Boid *obj, boidList) {
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
 * Each boid is deleted until #boidList is empty.
 */
void Management::clear() {
    while(!boidList.empty())
        removeBoid();
    while(!predList.empty()) {
        delete predList.back();
        predList.pop_back();
    }
}

/**
 * @brief Update Parameter::canvasHeight.
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
 * @brief Update Parameter::canvasWidth.
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
 * Parameter::speedFactor is set by the QML code and contains the factor by which every
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

/**
 * @brief Updates Parameters::mousePosition
 * @param x x-Position
 * @param y y-Position
 */
void Management::setMousePosition(double x, double y) {
    parameters.mousePosition.setX(x);
    parameters.mousePosition.setY(y);
}

/**
 * @brief Sets the size of the boids and predators
 * @param size Desired size
 */
void Management::setSize(uint size) {
    parameters.size = size;
}

/**
 * @brief Add a new boid to #boidList.
 */
void Management::addBoid() {
    boidList.push_back(new Boid());
}

/**
 * @brief Remove a boid from #boidList.
 */
void Management::removeBoid() {
    delete boidList.back();
    boidList.pop_back();
}

/**
 * @brief Add a new predator to #predList.
 */
void Management::addPredator() {
    predList.push_back(new Predator());
}

/**
 * @brief Remove a predator from #predList.
 */
void Management::removePredator() {
    delete predList.back();
    predList.pop_back();
}

void Management::prepareTree() {
    tree = kd_create(2);

    foreach (Boid *obj, boidList) {
        double position[2] = { obj->getX(), obj->getY()};
        kd_insert( tree, position, 0);
    }
}
