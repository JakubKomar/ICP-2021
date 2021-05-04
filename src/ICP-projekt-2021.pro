QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    core/atomic.cpp \
    core/block.cpp \
    core/aplication.cpp \
    core/compozit.cpp \
    core/connection.cpp \
    core/port.cpp \
    core/test.cpp \
    gui/blockmodel.cpp \
    gui/portlayout.cpp \
    gui/portmodel.cpp \
    main.cpp \
    mainwindow.cpp \
    gui/aplicationview.cpp

HEADERS += \
    core/aplication.h \
    core/atomic.h \
    core/block.h \
    core/compozit.h \
    core/connection.h \
    core/port.h \
    core/test.h \
    gui/blockmodel.h \
    gui/portlayout.h \
    gui/portmodel.h \
    mainwindow.h \
    gui/aplicationview.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    ICP-projekt-2021_cs_CZ.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
