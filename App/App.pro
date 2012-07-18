TEMPLATE = app
CONFIG  += console
CONFIG  -= qt
CONFIG  -= app_bundle
CONFIG  += debug
QT      -= core gui
#CONFIG += GPERFTOOLS # to compile with GPERFTOOLS support for code profiling

include($$PWD/../shared.pri)


# -----------------------------------------------------------------------------
# Our source and headers
# -----------------------------------------------------------------------------
SOURCES += \
    src/main.cpp \
    src/CommandLine.cpp \
    src/DrawHelper.cpp \
    src/IFunctionalTest.cpp \
    src/IsGISAXSTools.cpp \
    src/SampleFactory.cpp \
    src/StandardSamples.cpp \
    src/TestConvolution.cpp \
    src/TestDetectorResolution.cpp \
    src/TestDiffuseReflection.cpp \
    src/TestFactory.cpp \
    src/TestFormFactor.cpp \
    src/TestFresnelCoeff.cpp \
    src/TestIsGISAXS1.cpp \
    src/TestIsGISAXS3.cpp \
    src/TestIsGISAXS9.cpp \
    src/TestIsGISAXS10.cpp \
    src/TestMesoCrystal.cpp \
    src/TestRoughness.cpp \

HEADERS += \
    inc/App.h \
    inc/AppLinkDef.h \
    inc/CommandLine.h \
    inc/DrawHelper.h \
    inc/IFunctionalTest.h \
    inc/IsGISAXSTools.h \
    inc/SampleFactory.h \
    inc/StandardSamples.h \
    inc/TestConvolution.h \
    inc/TestDetectorResolution.h \
    inc/TestDiffuseReflection.h \
    inc/TestFactory.h \
    inc/TestFormFactor.h \
    inc/TestFresnelCoeff.h \
    inc/TestIsGISAXS1.h \
    inc/TestIsGISAXS3.h \
    inc/TestIsGISAXS9.h \
    inc/TestIsGISAXS10.h \
    inc/TestMesoCrystal.h \
    inc/TestRoughness.h \

INCLUDEPATH += ./inc ../Core/Algorithms/inc ../Core/Geometry/inc ../Core/Samples/inc ../Core/Tools/inc
DEPENDPATH  += ./inc ../Core/Algorithms/inc ../Core/Geometry/inc ../Core/Samples/inc ../Core/Tools/inc

OBJECTS_DIR = obj

# -----------------------------------------------------------------------------
# generating package dependency flags
# -----------------------------------------------------------------------------
MY_DEPENDENCY_LIB = ScattCore
MY_DEPENDENCY_DEST =$$PWD/..
SONAME = so
INCLUDEPATH += $${MY_DEPENDENCY_DEST}/inc
for(dep, MY_DEPENDENCY_LIB) {
    LIBS += $${MY_DEPENDENCY_DEST}/lib/lib$${dep}.$${SONAME}
    PRE_TARGETDEPS += $${MY_DEPENDENCY_DEST}/lib/lib$${dep}.$${SONAME}
    INCLUDEPATH += $${MY_DEPENDENCY_DEST}/inc/$${dep}
}


# -----------------------------------------------------------------------------
# external libraries
# -----------------------------------------------------------------------------
macx {
  INCLUDEPATH += /opt/local/include
  LIBS += -L/opt/local/lib
}
!macx:unix {
  INCLUDEPATH += /usr/local/include
  LIBS += -L/usr/local/lib -L/usr/lib64
}
# normally it should be done like that
LIBS += -lgsl -lgslcblas -lfftw3 -lboost_system -lboost_filesystem -lboost_regex

# here is workaround since JCNS /usr/local doesn't have shared fftw3
# qmake CONFIG+=JCNS
CONFIG(JCNS) {
  LIBS -= -lfftw3
  LIBS += -Bstatic -lfftw3 -Bdynamic # request for static (without fPIC option)
  # "-lfftw3f" - with fPIC option, "-lfftw3" - without fPIC option
}


# -----------------------------------------------------------------------------
# adding ROOT libraries
# -----------------------------------------------------------------------------
exists($$(ROOTSYS)/bin/root-config){
  INCLUDEPATH += $$system($ROOTSYS/bin/root-config --incdir)
  #LIBS += $$system($ROOTSYS/bin/root-config --glibs)
  LIBS += -L$$system($ROOTSYS/bin/root-config --libdir ) -lGui -lCore -lCint -lRIO -lHist -lGraf -lGraf3d -lGpad  -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lpthread -lm -ldl

  MYROOTCINT = ${ROOTSYS}/bin/rootcint
}
# if it doesn't exist, try to do something
!exists($$(ROOTSYS)/bin/root-config){
  INCLUDEPATH += /opt/local/include/root
  LIBS +=  -L/opt/local/lib/root -lGui -lCore -lCint -lRIO -lNet -lHist -lGraf -lGraf3d -lGpad -lTree -lRint -lPostscript -lMatrix -lPhysics -lMathCore -lThread -lpthread -lm -ldl
  MYROOTCINT = /opt/local/bin/rootcint
}



# -----------------------------------------------------------------------------
# Hand made addition to generate root dictionaries in the
# absence of rootcint.pri file
# -----------------------------------------------------------------------------
CREATE_ROOT_DICT_FOR_CLASSES = inc/App.h inc/AppLinkDef.h

DICTDEFINES += -DQT_VERSION=0x30000
QT_VERSION=$$[QT_VERSION]
contains( QT_VERSION, "^4.*" ) {
  DICTDEFINES -= -DQT_VERSION=0x30000
  DICTDEFINES *= -DQT_VERSION=0x40000
}
ROOT_CINT_TARGET = $${TARGET}
SOURCES         *= src/$${ROOT_CINT_TARGET}Dict.cpp
rootcint.target       = src/$${ROOT_CINT_TARGET}Dict.cpp
rootcint.commands    += $$MYROOTCINT
rootcint.commands    +=  -f $$rootcint.target  -c -I../Core/Tools/inc $$CREATE_ROOT_DICT_FOR_CLASSES
#rootcint.commands    +=  -f $$rootcint.target  -c -p $$DICTDEFINES $(INCPATH) $$CREATE_ROOT_DICT_FOR_CLASSES
rootcint.depends      = $$CREATE_ROOT_DICT_FOR_CLASSES

rootcintecho.commands = @echo "Generating dictionary $$rootcint.target for $$CREATE_ROOT_DICT_FOR_CLASSES classes"
QMAKE_EXTRA_TARGETS += rootcintecho rootcint
QMAKE_CLEAN       +=  src/$${ROOT_CINT_TARGET}Dict.cpp src/$${ROOT_CINT_TARGET}Dict.h




