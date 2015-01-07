#include "management.h"

vector<Boid*> Management::boidList;
vector<Predator*> Management::predList;
kdtree *Management::tree = nullptr;

bool initialized = false;
Parameter parameters;


Management::Management() {
}

/**
 * @brief Initialize the boidHelper class.
 *
 * Calls boidHelper::initialize with all required data.
 *
 * @param engine Main QQmlApplicationEngine of the application.
 * @param canvas QObject of the canvas.
 */
void Management::initialize(QQmlApplicationEngine *engine, QObject *canvas) {
    if(!initialized) {
        initialized = true;
        BoidHelper::initialize(engine, canvas, &tree, &parameters);
    }
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
    while(!predList.empty())
        removePredator();
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
 * @brief Set the velocity.
 * @param average Average velocity.
 */
void Management::setVelocity(double average) {
    parameters.velocity_max = average;
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
 * @brief Sets the flocking factor
 * @param flock current flocking factor
 */

void Management::setFlockingFactor(double flock) {
    parameters.factor_flocking = flock;
}
/**
 * @brief Sets the avoidance factor
 * @param avoid current avoidance factor
 */
void Management::setAvoidanceFactor(double avoid) {
    parameters.factor_avoidance = avoid;
}

/**
 * @brief Sets the velocity match factor
 * @param match current match factor
 */
void Management::setVelocityMatchFactor(double match) {
    parameters.factor_match = match;
}

/**
 * @brief Sets the target factor
 * @param target current target factor
 */
void Management::setTargetFactor(double target) {
    parameters.factor_target = target;
}
/**
 * @brief Sets the awareness radius
 * @param radius current awareness radius
 */
void Management::setAwarenessRadius(double radius){
    parameters.awarenessRadius = radius;
}

/**
 * @brief Sets the visualization of the radius
 * @param value
 */
void Management::setAwarenessRadiusVisualization(bool value) {
    parameters.visualizeAwarenessRadius = value;
}
/**
 * @brief Sets the followmode of the mouse
 * @param follow follow or avoid
 */
void Management::setMouseFollowMode(bool follow) {
    parameters.followMouse = follow;
}
/**
 * @brief Sets the boid color
 * @param color current boid color
 */
void Management::setColor(QColor color){
    parameters.mainColor = color;
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

/**
 * @brief inserts boid objects and their position into a kd-tree
 */
void Management::prepareTree() {
    tree = kd_create(2);

    foreach (Boid *obj, boidList) {
        double position[2] = { obj->getX(), obj->getY()};
        kd_insert( tree, position, obj);
    }
    foreach (Predator *pred, predList) {
        double position2[2] = {pred->getX(), pred->getY()};
        kd_insert(tree, position2, pred);
    }
}


