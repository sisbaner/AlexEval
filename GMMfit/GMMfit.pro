#-------------------------------------------------
#
# Project created by QtCreator 2013-08-30T19:32:15
#
#-------------------------------------------------

QT       -= core gui

TARGET = GMMfit
TEMPLATE = lib

DEFINES += GMMFIT_LIBRARY

INCLUDEPATH += ../../../FCSTOOLS/trunk/QuickFit3/extlibs/eigen/eigen/
#LIBS += ../../../FCSTOOLS/trunk/QuickFit3/extlibs/eigen/eigen/Eigen

SOURCES += GMMfit.cpp

HEADERS += GMMfit.h

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
