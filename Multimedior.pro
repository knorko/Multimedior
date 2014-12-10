TEMPLATE = app

QT += qml quick

QMAKE_CXXFLAGS += -std=c++11

SOURCES += main.cpp \
    System/boid.cpp \
    System/management.cpp \
    System/boidhelper.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    System/management.h \
    System/boid.h \
    System/boidhelper.h

OTHER_FILES +=
