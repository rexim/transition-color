TEMPLATE = app
TARGET = transition-color
INCLUDEPATH += .
QT += widgets
QMAKE_CXXFLAGS += -Werror -std=c++11 -ggdb

SOURCES += main.cpp colorvector.cpp transitioncolorwidget.cpp
HEADERS += colorvector.hpp mathutils.hpp transitioncolorwidget.hpp
