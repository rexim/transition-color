TEMPLATE = app
TARGET = transition-color
INCLUDEPATH += .
QT += widgets
QMAKE_CXXFLAGS += -Werror -std=c++11 -ggdb

SOURCES += main.cpp \
           colorvector.cpp \
           colorwidget.cpp \
           transitioncolorengine.cpp \
           timerwithdeltatime.cpp \
           mainwindow.cpp

HEADERS += colorvector.hpp \
           mathutils.hpp \
           colorwidget.hpp \
           transitioncolorengine.hpp \
           timerwithdeltatime.hpp \
           mainwindow.hpp

FORMS += mainwindow.ui
