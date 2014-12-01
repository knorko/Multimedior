TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    System/boid.cpp \
    System/coordinate.cpp \
    System/management.cpp \
    System/navigation.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    System/boid.h \
    System/coordinate.h \
    System/management.h \
    System/navigation.h

OTHER_FILES +=
