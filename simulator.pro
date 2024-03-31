#-------------------------------------------------
#
# Project created by QtCreator 2013-01-22T14:21:20
#
#-------------------------------------------------

TEMPLATE = app
TARGET = simulator
DEPENDPATH += . img src ui obj
INCLUDEPATH += . src obj 

QT += gui widgets core printsupport
CONFIG += debug

#CONFIG += c++11 mobility
#MOBILITY =

win32: {
CONFIG += c++11 mobility
DEFINES += ANDROID
ANDROID_PACKAGE_SOURCE_DIR += ../simulator/android
}

# Options
DESTDIR        = bin
TARGET_DIR     = bin
OBJECTS_DIR    = obj
MOC_DIR        = obj
UI_DIR         = ui
UI_HEADERS_DIR = obj
RCC_DIR        = obj

LIBS += -lwfdb

# Input
HEADERS += \
    src/Control/Question/level/level.h \
    src/Control/Question/level10/level10.h \
    src/Control/Question/level11/level11.h \
    src/Control/Question/level12/level12.h \
    src/Control/Question/level2/level2_form.h \
    src/Control/Question/level3/level3_form.h \
    src/Control/Question/level4/level4.h \
    src/Control/Question/level5/level5.h \
    src/Control/Question/level6/level6.h \
    src/Control/Question/level7/level7.h \
    src/Control/Question/level8/level8.h \
    src/Control/Question/level9/level9.h \
    src/Diograms/Diograms_Data/diograms_data.h \
    src/Diograms/Diograms_Fun/diograms_fun.h \
    src/Diograms/Enum/listdata.h \
    src/Tratining/Form/tratining_form.h \
    src/Tratining/Servise/servise_plot.h \
    src/Utilities/qcustomplot.h \
    src/Control/Question/QuestionPattern/questionpattern_form.h \
    src/Control/Question/level1/level1_form.h \
    src/Control/Form/controlmode_form.h \
    src/Simulator/simulator.h \
    src/Utilities/delegate.h
FORMS += \
    src/Control/Question/QuestionPattern/questionpattern_form.ui \
    src/Control/Question/level1/level1_form.ui \
    src/Control/Question/level2/level2_form.ui \
    src/Control/Question/level3/level3_form.ui \
    src/Control/Form/controlmode_form.ui \
    src/Tratining/Form/tratining_form.ui \
    ui/simulator.ui
SOURCES += \
    src/Control/Question/level10/level10.cpp \
    src/Control/Question/level11/level11.cpp \
    src/Control/Question/level12/level12.cpp \
    src/Control/Question/level2/level2_form.cpp \
    src/Control/Question/level3/level3_form.cpp \
    src/Control/Question/level4/level4.cpp \
    src/Control/Question/level5/level5.cpp \
    src/Control/Question/level6/level6.cpp \
    src/Control/Question/level7/level7.cpp \
    src/Control/Question/level8/level8.cpp \
    src/Control/Question/level9/level9.cpp \
    src/Diograms/Diograms_Data/diograms_data.cpp \
    src/Diograms/Diograms_Fun/diograms_fun.cpp \
    src/Diograms/Enum/listdata.cpp \
    src/Tratining/Form/tratining_form.cpp \
    src/Tratining/Servise/servise_plot.cpp \
    src/Utilities/qcustomplot.cpp \
    src/Control/Question/QuestionPattern/questionpattern_form.cpp \
    src/Control/Question/level1/level1_form.cpp \
    src/Control/Form/controlmode_form.cpp \
    src/Simulator/simulator.cpp \
    src/main.cpp \
    src/Utilities/delegate.cpp


RESOURCES += img/application.qrc

