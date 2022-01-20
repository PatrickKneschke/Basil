TARGET  += basil

TEMPLATE = app
CONFIG  += release_debug
QT		+= widgets

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += basil.h ui_basil.h stopwatch.h
SOURCES += main.cpp basil.cpp stopwatch.cpp
