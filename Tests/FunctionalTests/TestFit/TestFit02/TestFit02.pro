TEMPLATE = app
CONFIG  += console
CONFIG  -= qt app_bundle
QT      -= core gui

CONFIG+= BORNAGAIN_ROOT

INCLUDEPATH += $$PWD/../../../../Fit/Factory/inc
DEPENDPATH  += $$PWD/../../../../Fit/Factory/inc

include($$PWD/../../../../shared.pri)
DEFINES += STANDALONE
LIBS += $$PWD/../../../../lib/libBornAgainCore.so $$PWD/../../../../lib/libBornAgainFit.so $$PWD/../../../../lib/libRootMathMore.$${SONAME}


SOURCES += TestFit02.cpp \
    SampleBuilder.cpp
HEADERS += TestFit02.h \
    SampleBuilder.h

