TEMPLATE      = app
INCLUDEPATH += ../../../LIB/trunk/ \
               ../../../LIB/trunk/qt/\
               ../../../FCSTOOLS/trunk/QuickFit3/extlibs/eigen/eigen/
#DEFINES *= QT_USE_QSTRINGBUILDER // not entirely source compatible

include(gsl.pri)

HEADERS       =    ../../../LIB/trunk/logfile.h \
    ../../../LIB/trunk/jkiniparser.h \
    ../../../LIB/trunk/highrestimer.h \
    ../../../LIB/trunk/datatable.h \
    ../../../LIB/trunk/tools.h \
    ../../../LIB/trunk/qt/qmodernprogresswidget.h \
    ../../../LIB/trunk/jkiniparser2.h \
    ../../../LIB/trunk/jkmathparser.h \
    tillmanneval.h \
    ../../../LIB/trunk/statistics_tools.h \
    ../../../LIB/trunk/multitau-correlator.h \
    parameters.h \
    readArrivalTimes.h \
    BurstSearch.h \
    analysis.h \
    ../../../LIB/trunk/qt/jkqtptools.h \
    ../../../LIB/trunk/qt/jkqtpparsedfunctionelements.h \
    ../../../LIB/trunk/qt/jkqtpoverlayelements.h \
    ../../../LIB/trunk/qt/jkqtplotter.h \
    ../../../LIB/trunk/qt/jkqtpimagetools.h \
    ../../../LIB/trunk/qt/jkqtpimageelements.h \
    ../../../LIB/trunk/qt/jkqtpgeoelements.h \
    ../../../LIB/trunk/qt/jkqtpelements.h \
    ../../../LIB/trunk/qt/jkqtpdatastorage.h \
    ../../../LIB/trunk/qt/jkqtpbaseplotter.h \
    ../../../LIB/trunk/qt/jkqtpbaseelements.h \
    ../../../LIB/trunk/qt/jkqtmathtext.h \
    ../../../LIB/trunk/qt/qtlogfile.h \
    ../../../LIB/trunk/qt/qenhancedlineedit.h \
    ../../../LIB/trunk/qt/jkstyledbutton.h \
    photonswidget.h \
    burstsearchwidget.h \
    alexhistogramswidget.h \
    mainwindow.h \
    alexplots.h \
    alexdata.h \
    burst.h \
    compareburstsearch.h \
    DialogReconstructMarkerRecords.h \
    BurstView.h \
    BurstStatisticsView.h \
    dialogTable.h \
    alexevallog.h \
    ../../../LIB/trunk/GMMfit/GMMfit.h \
    FCSwidget.h \
    DialogGMMparams.h \
    FCSdata.h \
    FCScurve.h


SOURCES       = main.cpp \
    ../../../LIB/trunk/tools.cpp \
    ../../../LIB/trunk/logfile.cpp \
    ../../../LIB/trunk/jkiniparser.cpp \
    ../../../LIB/trunk/highrestimer.cpp \
    ../../../LIB/trunk/datatable.cpp \
    ../../../LIB/trunk/qt/qmodernprogresswidget.cpp \
    ../../../LIB/trunk/jkmathparser.cpp \
    ../../../LIB/trunk/jkiniparser2.cpp \
    tillmanneval.cpp \
    ../../../LIB/trunk/statistics_tools.cpp \
    readArrivalTimes.cpp \
    BurstSearch.cpp \
    analysis.cpp \
    parameters.cpp \
    ../../../LIB/trunk/qt/jkqtptools.cpp \
    ../../../LIB/trunk/qt/jkqtpparsedfunctionelements.cpp \
    ../../../LIB/trunk/qt/jkqtpoverlayelements.cpp \
    ../../../LIB/trunk/qt/jkqtplotter.cpp \
    ../../../LIB/trunk/qt/jkqtpimagetools.cpp \
    ../../../LIB/trunk/qt/jkqtpimageelements.cpp \
    ../../../LIB/trunk/qt/jkqtpgeoelements.cpp \
    ../../../LIB/trunk/qt/jkqtpelements.cpp \
    ../../../LIB/trunk/qt/jkqtpdatastorage.cpp \
    ../../../LIB/trunk/qt/jkqtpbaseplotter.cpp \
    ../../../LIB/trunk/qt/jkqtpbaseelements.cpp \
    ../../../LIB/trunk/qt/jkqtmathtext.cpp \
    ../../../LIB/trunk/qt/jkstyledbutton.cpp \
    ../../../LIB/trunk/qt/qtlogfile.cpp \
    ../../../LIB/trunk/qt/qenhancedlineedit.cpp \
    photonswidget.cpp \
    burstsearchwidget.cpp \
    alexhistogramswidget.cpp \
    mainwindow.cpp \
    alexplots.cpp \
    alexdata.cpp \
    burst.cpp \
    compareburstsearch.cpp \
    DialogReconstructMarkerRecords.cpp \
    BurstView.cpp \
    BurstStatisticsView.cpp \
    dialogTable.cpp \
    alexevallog.cpp \
    ../../../LIB/trunk/GMMfit/GMMfit.cpp \
    FCSwidget.cpp \
    DialogGMMparams.cpp \
    FCSdata.cpp \
    FCScurve.cpp



FORMS += \
    photonswidget.ui \
    burstsearchwidget.ui \
    alexhistogramswidget.ui \
    DialogReconstructMarkerRecords.ui \
    BurstStatisticsView.ui \
    BurstView.ui \
    dialogTable.ui \
    FCSwidget.ui \
    DialogGMMparams.ui

OTHER_FILES +=  Notes.txt \
    snippets.cpp \
    ../../../LIB/trunk/qt/jkqtplotter.pri \
    alex.ini \
    debug/alexeval.ini \
    AlexEval.rc

RCC_DIR = ./.rccs
UI_DIR = ./.uis
OBJECTS_DIR = ./.objs
MOC_DIR = ./.mocs

RC_FILE = AlexEval.rc

RESOURCES += \
    ../../../LIB/trunk/qt/jkqtpbaseplotter.qrc \
    ../../../LIB/trunk/qt/qtlogfile.qrc \
    ../../../LIB/trunk/qt/jkstyledbutton.qrc

QT += svg xml
