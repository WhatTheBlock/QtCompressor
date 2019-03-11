#-------------------------------------------------
#
# Project created by QtCreator 2017-11-14T01:27:41
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtCompressor
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dialog1.cpp

HEADERS += \
        mainwindow.h \
    dialog1.h \
    filedl.h \
    ui_mainwindow.h

FORMS += \
        mainwindow.ui \
    dialog1.ui

RESOURCES += resource.qrc

win32 {
    CONFIG -= embed_manifest_exe
    RC_FILE = admin_icon.rc
}

*msvc* { # visual studio spec filter
      QMAKE_CXXFLAGS += -MP
  }