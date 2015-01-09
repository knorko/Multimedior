/****************************************************************************
** Meta object code from reading C++ file 'management.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "System/management.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'management.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Management_t {
    QByteArrayData data[39];
    char stringdata[435];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Management_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Management_t qt_meta_stringdata_Management = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 4),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 9),
QT_MOC_LITERAL(4, 27, 13),
QT_MOC_LITERAL(5, 41, 3),
QT_MOC_LITERAL(6, 45, 5),
QT_MOC_LITERAL(7, 51, 15),
QT_MOC_LITERAL(8, 67, 6),
QT_MOC_LITERAL(9, 74, 14),
QT_MOC_LITERAL(10, 89, 5),
QT_MOC_LITERAL(11, 95, 8),
QT_MOC_LITERAL(12, 104, 11),
QT_MOC_LITERAL(13, 116, 11),
QT_MOC_LITERAL(14, 128, 7),
QT_MOC_LITERAL(15, 136, 16),
QT_MOC_LITERAL(16, 153, 1),
QT_MOC_LITERAL(17, 155, 1),
QT_MOC_LITERAL(18, 157, 7),
QT_MOC_LITERAL(19, 165, 4),
QT_MOC_LITERAL(20, 170, 17),
QT_MOC_LITERAL(21, 188, 5),
QT_MOC_LITERAL(22, 194, 18),
QT_MOC_LITERAL(23, 213, 5),
QT_MOC_LITERAL(24, 219, 22),
QT_MOC_LITERAL(25, 242, 5),
QT_MOC_LITERAL(26, 248, 15),
QT_MOC_LITERAL(27, 264, 6),
QT_MOC_LITERAL(28, 271, 8),
QT_MOC_LITERAL(29, 280, 5),
QT_MOC_LITERAL(30, 286, 18),
QT_MOC_LITERAL(31, 305, 6),
QT_MOC_LITERAL(32, 312, 31),
QT_MOC_LITERAL(33, 344, 5),
QT_MOC_LITERAL(34, 350, 18),
QT_MOC_LITERAL(35, 369, 6),
QT_MOC_LITERAL(36, 376, 16),
QT_MOC_LITERAL(37, 393, 19),
QT_MOC_LITERAL(38, 413, 21)
    },
    "Management\0init\0\0boidCount\0predatorCount\0"
    "run\0clear\0setCanvasHeight\0height\0"
    "setCanvasWidth\0width\0setSpeed\0speedFactor\0"
    "setVelocity\0average\0setMousePosition\0"
    "x\0y\0setSize\0size\0setFlockingFactor\0"
    "flock\0setAvoidanceFactor\0avoid\0"
    "setVelocityMatchFactor\0match\0"
    "setTargetFactor\0target\0setColor\0color\0"
    "setAwarenessRadius\0radius\0"
    "setAwarenessRadiusVisualization\0value\0"
    "setMouseFollowMode\0follow\0addMousePosition\0"
    "removeMousePosition\0getMousePositionCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Management[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    2,  114,    2, 0x02 /* Public */,
       5,    0,  119,    2, 0x02 /* Public */,
       6,    0,  120,    2, 0x02 /* Public */,
       7,    1,  121,    2, 0x02 /* Public */,
       9,    1,  124,    2, 0x02 /* Public */,
      11,    1,  127,    2, 0x02 /* Public */,
      13,    1,  130,    2, 0x02 /* Public */,
      15,    2,  133,    2, 0x02 /* Public */,
      18,    1,  138,    2, 0x02 /* Public */,
      20,    1,  141,    2, 0x02 /* Public */,
      22,    1,  144,    2, 0x02 /* Public */,
      24,    1,  147,    2, 0x02 /* Public */,
      26,    1,  150,    2, 0x02 /* Public */,
      28,    1,  153,    2, 0x02 /* Public */,
      30,    1,  156,    2, 0x02 /* Public */,
      32,    1,  159,    2, 0x02 /* Public */,
      34,    1,  162,    2, 0x02 /* Public */,
      36,    2,  165,    2, 0x02 /* Public */,
      37,    0,  170,    2, 0x02 /* Public */,
      38,    0,  171,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Double,   10,
    QMetaType::Void, QMetaType::Double,   12,
    QMetaType::Void, QMetaType::Double,   14,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   16,   17,
    QMetaType::Void, QMetaType::UInt,   19,
    QMetaType::Void, QMetaType::Double,   21,
    QMetaType::Void, QMetaType::Double,   23,
    QMetaType::Void, QMetaType::Double,   25,
    QMetaType::Void, QMetaType::Double,   27,
    QMetaType::Void, QMetaType::QColor,   29,
    QMetaType::Void, QMetaType::Double,   31,
    QMetaType::Void, QMetaType::Bool,   33,
    QMetaType::Void, QMetaType::Bool,   35,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   16,   17,
    QMetaType::Void,
    QMetaType::Int,

       0        // eod
};

void Management::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Management *_t = static_cast<Management *>(_o);
        switch (_id) {
        case 0: _t->init((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 1: _t->run(); break;
        case 2: _t->clear(); break;
        case 3: _t->setCanvasHeight((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->setCanvasWidth((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->setSpeed((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->setVelocity((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->setMousePosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 8: _t->setSize((*reinterpret_cast< uint(*)>(_a[1]))); break;
        case 9: _t->setFlockingFactor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 10: _t->setAvoidanceFactor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setVelocityMatchFactor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->setTargetFactor((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 13: _t->setColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 14: _t->setAwarenessRadius((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 15: _t->setAwarenessRadiusVisualization((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->setMouseFollowMode((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->addMousePosition((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 18: _t->removeMousePosition(); break;
        case 19: { int _r = _t->getMousePositionCount();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = _r; }  break;
        default: ;
        }
    }
}

const QMetaObject Management::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Management.data,
      qt_meta_data_Management,  qt_static_metacall, 0, 0}
};


const QMetaObject *Management::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Management::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Management.stringdata))
        return static_cast<void*>(const_cast< Management*>(this));
    return QObject::qt_metacast(_clname);
}

int Management::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
