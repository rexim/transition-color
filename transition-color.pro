TEMPLATE = app
TARGET = transition-color
INCLUDEPATH += .
QT += widgets
QMAKE_CXXFLAGS += -Werror -std=c++11 -ggdb

SOURCES += main.cpp \
           colorvector.cpp \
           colorwidget.cpp \
           colortransitor.cpp \
           timerwithdeltatime.cpp

HEADERS += colorvector.hpp \
           mathutils.hpp \
           colorwidget.hpp \
           colortransitor.hpp \
           timerwithdeltatime.hpp
