TEMPLATE = app

QT += qml quick

QMAKE_CXXFLAGS += -std=c++11


# Defines:
# BOID_DEBUG    - Enable verbose logging
DEFINES +=

SOURCES += main.cpp \
    System/boid.cpp \
    System/management.cpp \
    System/boidhelper.cpp \
    System/kdtree.c \
    System/vector2.cpp \
    System/predator.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    System/management.h \
    System/boid.h \
    System/boidhelper.h \
    System/kdtree.h \
    System/vector2.h \
    System/predator.h \
    System/parameter.h

OTHER_FILES +=
