#-------------------------------------------------
#
# Project created by QtCreator 2014-12-16T09:03:16
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CAM_SHOT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qglobalshortcut.cc \
    qglobalshortcut_win.cc \
    camshooter.cpp \
    dialog.cpp \
    camera.cpp \
    selectdialog.cpp

HEADERS  += mainwindow.h \
    qglobalshortcut.h \
    camshooter.h \
    dialog.h \
    camera.h \
    selectdialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    selectdialog.ui

QMAKE_CXXFLAGS += -std=c++0x
