TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

INCLUDEPATH += $$PWD/include/

SOURCES += main.cpp

LIBS += -lsfml-graphics -lsfml-system -lsfml-window -lz

SOURCES += $$PWD/src/*.cpp
HEADERS += $$PWD/include/*.hpp

include(deployment.pri)
qtcAddDeployment()

