TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
INCLUDEPATH += F:\Important\Graduation\ZuCar2018\CarModel\CarModelQt\CarMathModel\PathTracking

MATLAB_PATH = F:\Program Files\MATLAB\R2016a\extern
message($$MATLAB_PATH)
INCLUDEPATH += F:\Program Files\MATLAB\R2016a\extern\include
LIBS += -L$$MATLAB_PATH\lib\win64\microsoft

SHARED_LIB_FILES = $$files($(MATLAB_PATH)\lib\win64\microsoft\*.lib)
    for(FILE, SHARED_LIB_FILES) {
        BASENAME = $$basename(FILE)
        LIBS += -l$$replace(BASENAME,.lib,)
    }

SOURCES += \
    KiAngularVelocity.cpp
