/****************************************************************************
** Meta object code from reading C++ file 'ImageViewer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "ImageViewer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ImageViewer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ImageViewer_t {
    QByteArrayData data[20];
    char stringdata0[292];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ImageViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ImageViewer_t qt_meta_stringdata_ImageViewer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ImageViewer"
QT_MOC_LITERAL(1, 12, 18), // "updateItemGeometry"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 6), // "newPos"
QT_MOC_LITERAL(4, 39, 10), // "onWorkDone"
QT_MOC_LITERAL(5, 50, 14), // "processedImage"
QT_MOC_LITERAL(6, 65, 21), // "onZoomInButtonClicked"
QT_MOC_LITERAL(7, 87, 22), // "onPressMouseLeftButton"
QT_MOC_LITERAL(8, 110, 22), // "onZoomOutButtonClicked"
QT_MOC_LITERAL(9, 133, 19), // "onFileButtonClicked"
QT_MOC_LITERAL(10, 153, 19), // "onSaveButtonClicked"
QT_MOC_LITERAL(11, 173, 18), // "updateImageDisplay"
QT_MOC_LITERAL(12, 192, 17), // "saveImageInternal"
QT_MOC_LITERAL(13, 210, 12), // "startDrawing"
QT_MOC_LITERAL(14, 223, 18), // "deleteCurrentImage"
QT_MOC_LITERAL(15, 242, 11), // "rotateImage"
QT_MOC_LITERAL(16, 254, 14), // "addTextToImage"
QT_MOC_LITERAL(17, 269, 4), // "text"
QT_MOC_LITERAL(18, 274, 10), // "scaleImage"
QT_MOC_LITERAL(19, 285, 6) // "factor"

    },
    "ImageViewer\0updateItemGeometry\0\0newPos\0"
    "onWorkDone\0processedImage\0"
    "onZoomInButtonClicked\0onPressMouseLeftButton\0"
    "onZoomOutButtonClicked\0onFileButtonClicked\0"
    "onSaveButtonClicked\0updateImageDisplay\0"
    "saveImageInternal\0startDrawing\0"
    "deleteCurrentImage\0rotateImage\0"
    "addTextToImage\0text\0scaleImage\0factor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ImageViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   87,    2, 0x0a /* Public */,
       6,    0,   90,    2, 0x0a /* Public */,
       7,    0,   91,    2, 0x0a /* Public */,
       8,    0,   92,    2, 0x0a /* Public */,
       9,    0,   93,    2, 0x0a /* Public */,
      10,    0,   94,    2, 0x0a /* Public */,
      11,    0,   95,    2, 0x0a /* Public */,
      12,    0,   96,    2, 0x0a /* Public */,
      13,    0,   97,    2, 0x0a /* Public */,
      14,    0,   98,    2, 0x0a /* Public */,
      15,    0,   99,    2, 0x0a /* Public */,
      16,    1,  100,    2, 0x0a /* Public */,
      18,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPointF,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::Double,   19,

       0        // eod
};

void ImageViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ImageViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updateItemGeometry((*reinterpret_cast< QPointF(*)>(_a[1]))); break;
        case 1: _t->onWorkDone((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->onZoomInButtonClicked(); break;
        case 3: _t->onPressMouseLeftButton(); break;
        case 4: _t->onZoomOutButtonClicked(); break;
        case 5: _t->onFileButtonClicked(); break;
        case 6: _t->onSaveButtonClicked(); break;
        case 7: _t->updateImageDisplay(); break;
        case 8: _t->saveImageInternal(); break;
        case 9: _t->startDrawing(); break;
        case 10: _t->deleteCurrentImage(); break;
        case 11: _t->rotateImage(); break;
        case 12: _t->addTextToImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->scaleImage((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ImageViewer::*)(QPointF );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ImageViewer::updateItemGeometry)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ImageViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_ImageViewer.data,
    qt_meta_data_ImageViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ImageViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ImageViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ImageViewer.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int ImageViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void ImageViewer::updateItemGeometry(QPointF _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
