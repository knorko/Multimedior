#include "management.h"

vector<boid*> management::objList;
kdtree *management::tree = nullptr;

double management::canvasHeight = 472;
double management::canvasWidth = 612;
double management::speed = 1;

/**
 * @brief Initialize the boidHelper class.
 *
 * Calls boidHelper::initialize with all required data.
 *
 * @param engine Main QQmlApplicationEngine of the application.
 * @param canvas QObject of the canvas.
 */
management::management(QQmlApplicationEngine *engine, QObject *canvas) {
    boidHelper::initialize(engine, canvas, &canvasHeight, &canvasWidth, &tree, &speed);
}

/**
 * @brief Set amount of desired boids.
 *
 * Delete or create boids until #objList holds the desired amount of references.
 *
 * @param count Desired amount of boids.
 */
void management::init(uint count) {
    void (*operation)() = objList.size() < count ? &addBoid : &removeBoid;

    while(objList.size() != count)
        operation();
}

/**
 * @brief Run the boid update routine
 *
 * First the kd-tree is prepared, then all boids have their boid::prepare(), boid::Update()
 * and boid::finalize() functions called (in that order).
 *
 * Afterwards we clear and free the kd-tree.
 */
void management::run() {
    prepareTree();

    foreach (boid *obj, objList) {
        obj->prepare();
        obj->Update();
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
void management::clear() {
    while(!objList.empty())
        removeBoid();
}

/**
 * @brief Update #canvasHeight.
 *
 * The actual height of the canvas is stored in a variable instead of being
 * retrieved from the UI every time.
 *
 * @param height Current canvas height.
 */
void management::setCanvasHeight(double height) {
    canvasHeight = height;
}

/**
 * @brief Update #canvasWidth.
 *
 * The actual width of the canvas is stored in a variable instead of being
 * retrieved from the UI every time.
 *
 * @param width Current canvas width.
 */
void management::setCanvasWidth(double width) {
    canvasWidth = width;
}

/**
 * @brief Update speed factor.
 *
 * #speed is set by the QML code and contains the factor by which every
 * boid movement is multiplied.
 *
 * @param speed Current speed factor.
 */
void management::setSpeed(double speed) {
    this->speed = speed;
}

/**
 * @brief Add a new boid to #objList.
 */
void management::addBoid() {
    objList.push_back(new boid());
}

/**
 * @brief Remove a boid from #objList.
 */
void management::removeBoid() {
    delete objList.back();
    objList.pop_back();
}

void management::prepareTree() {
    tree = kd_create(2);

    foreach (boid *obj, objList) {
        double position[2] = { obj->getX(), obj->getY()};
        kd_insert( tree, position, 0);
    }
}
