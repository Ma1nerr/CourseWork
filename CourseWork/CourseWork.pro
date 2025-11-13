QT       += core gui widgets

CONFIG   += c++17 console
CONFIG   -= app_bundle

TARGET = CarTableQt
TEMPLATE = app

SOURCES += \
    main.cpp \
    MainWindow.cpp \
    Car.cpp \
    StartupDialog.cpp \
    EditDialog.cpp \
    OperationsWindow.cpp

HEADERS += \
    MainWindow.h \
    Car.h \
    StartupDialog.h \
    EditDialog.h \
    OperationsWindow.h

FORMS += \
    MainWindow.ui \
    StartupDialog.ui \
    EditDialog.ui \
    OperationsWindow.ui

DISTFILES += sample_cars.dat README.md
