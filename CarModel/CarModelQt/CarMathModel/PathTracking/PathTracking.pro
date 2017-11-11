#-------------------------------------------------
#
# Project created by QtCreator 2017-10-29T20:10:01
#
#-------------------------------------------------

QT       -= gui

TARGET = PathTracking
TEMPLATE = lib
DEFINES += USE_QT
CONFIG(!staticlib){
    DEFINES += PATHTRACKING_LIBRARY
    HEADERS += pathtracking_global.h

}
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
    basekinematicmodel/kinematicimpls.h \
    basekinematicmodel/kinematicmodel.h \
    basekinematicmodel/kinematics.h \
    carkinematics/carkinematics.h \
    frenetkinematics/FrenetKinematics.h \
    cardescription.h

SOURCES += \
    basekinematicmodel/kinematicmodel.cpp \
    basekinematicmodel/kinematics.cpp \
    cardescription.cpp



#Headers To Be Added Here
unix {

    target.path = /usr/lib
    INSTALLS += target
}

linux{
# Linux Config Goes Here
}
win32{
# Windows Config Goes Here
 win32-msvc{
    #...
DESTDIR += $$_PRO_FILE_PWD_\..\..\..\libs

HSRCPATH = $$_PRO_FILE_PWD_\\*.h
HSRCPATH ~= s,/,\\,g

HDSTPATH = $$_PRO_FILE_PWD_\..\..\..\includes
HDSTPATH ~= s,/,\\,g
debug{
OSRCPATH = $$OUT_PWD\debug\*.obj
}release{
OSRCPATH = $$OUT_PWD\debug\*.obj

}
OSRCPATH ~= s,/,\\,g

ODSTPATH = $$_PRO_FILE_PWD_\..\..\..\libs
ODSTPATH ~= s,/,\\,g

COPY_CMD_INCLUDES = "xcopy $$HSRCPATH $$HDSTPATH /siy"
COPY_CMD_OBJS = "xcopy $$OSRCPATH $$ODSTPATH /siy"

QMAKE_POST_LINK += "$$COPY_CMD_INCLUDES && $$COPY_CMD_OBJS"

}



}



