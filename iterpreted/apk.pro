QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): 

CONFIG += c++17

SOURCES += \
    apk.cpp

HEADERS += \
    

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
