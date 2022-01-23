TARGET  = basil

TEMPLATE = app
QT		+= widgets 
QT      += multimedia

DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += basil.h ui_basil.h stopwatch.h
SOURCES += main.cpp basil.cpp stopwatch.cpp
