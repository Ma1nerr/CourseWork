/****************************************************************************
** Meta object code from reading C++ file 'OperationsWindow.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../OperationsWindow.h"
#include <QtCore/qmetatype.h>
#include <QtCore/QList>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'OperationsWindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN16OperationsWindowE_t {};
} // unnamed namespace

template <> constexpr inline auto OperationsWindow::qt_create_metaobjectdata<qt_meta_tag_ZN16OperationsWindowE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "OperationsWindow",
        "carsSorted",
        "",
        "QList<Car>",
        "sortedCars",
        "on_sortColorAscButton_clicked",
        "on_sortColorDescButton_clicked",
        "on_sortPriceAscButton_clicked",
        "on_sortPriceDescButton_clicked",
        "on_sortPowerAscButton_clicked",
        "on_sortPowerDescButton_clicked",
        "on_findBrandButton_clicked",
        "on_samePriceDiffColorButton_clicked",
        "on_priceRangeButton_clicked",
        "on_brandColorQueriesButton_clicked",
        "on_colorMinMaxButton_clicked",
        "on_closeButton_clicked",
        "on_clearResultsButton_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'carsSorted'
        QtMocHelpers::SignalData<void(const QVector<Car> &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { 0x80000000 | 3, 4 },
        }}),
        // Slot 'on_sortColorAscButton_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_sortColorDescButton_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_sortPriceAscButton_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_sortPriceDescButton_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_sortPowerAscButton_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_sortPowerDescButton_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_findBrandButton_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_samePriceDiffColorButton_clicked'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_priceRangeButton_clicked'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_brandColorQueriesButton_clicked'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_colorMinMaxButton_clicked'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_closeButton_clicked'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_clearResultsButton_clicked'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<OperationsWindow, qt_meta_tag_ZN16OperationsWindowE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject OperationsWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16OperationsWindowE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16OperationsWindowE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16OperationsWindowE_t>.metaTypes,
    nullptr
} };

void OperationsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<OperationsWindow *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->carsSorted((*reinterpret_cast<std::add_pointer_t<QList<Car>>>(_a[1]))); break;
        case 1: _t->on_sortColorAscButton_clicked(); break;
        case 2: _t->on_sortColorDescButton_clicked(); break;
        case 3: _t->on_sortPriceAscButton_clicked(); break;
        case 4: _t->on_sortPriceDescButton_clicked(); break;
        case 5: _t->on_sortPowerAscButton_clicked(); break;
        case 6: _t->on_sortPowerDescButton_clicked(); break;
        case 7: _t->on_findBrandButton_clicked(); break;
        case 8: _t->on_samePriceDiffColorButton_clicked(); break;
        case 9: _t->on_priceRangeButton_clicked(); break;
        case 10: _t->on_brandColorQueriesButton_clicked(); break;
        case 11: _t->on_colorMinMaxButton_clicked(); break;
        case 12: _t->on_closeButton_clicked(); break;
        case 13: _t->on_clearResultsButton_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (OperationsWindow::*)(const QVector<Car> & )>(_a, &OperationsWindow::carsSorted, 0))
            return;
    }
}

const QMetaObject *OperationsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *OperationsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16OperationsWindowE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int OperationsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void OperationsWindow::carsSorted(const QVector<Car> & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
