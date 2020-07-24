TEMPLATE = app

TARGET = pwkbridge

INCLUDEPATH += .

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += JSBridge.h
SOURCES += JSBridge.cpp pwkbridge.cpp

QT += webkitwidgets 
