#-------------------------------------------------
#
# Project created by QtCreator 2019-04-12T05:01:34
#
#-------------------------------------------------

QT       += core gui
QT += serialbus
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VirtualIC
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
    backgrounditem.cpp \
    datatextone.cpp \
    datatextonec.cpp \
    datatextonered.cpp \
    datatextonewhite.cpp \
    datatexttwo.cpp \
    datatexttwoc.cpp \
    datatexttwored.cpp \
    datatexttwowhite.cpp \
    endredone.cpp \
    endredtwo.cpp \
    infotext.cpp \
    turnsignal.cpp \
    datatextthree.cpp \
    datatextthreec.cpp \
    datatextthreewhite.cpp \
    datatextthreered.cpp \
    endredthree.cpp \
    leftblinkeranimation.cpp \
    rightblinkeranimation.cpp \
    speedanimation.cpp \
    aboutvic.cpp \
    datatextfour.cpp \
    datatextfourc.cpp \
    datatextfourwhite.cpp \
    datatextfourred.cpp \
    endredfour.cpp \
    datatextfive.cpp

HEADERS += \
        mainwindow.h \
    backgrounditem.h \
    datatextone.h \
    datatextonec.h \
    datatextonered.h \
    datatextonewhite.h \
    datatexttwo.h \
    datatexttwoc.h \
    datatexttwored.h \
    datatexttwowhite.h \
    endredone.h \
    endredtwo.h \
    infotext.h \
    turnsignal.h \
    datatextthree.h \
    datatextthreec.h \
    datatextthreewhite.h \
    datatextthreered.h \
    endredthree.h \
    leftblinkeranimation.h \
    rightblinkeranimation.h \
    speedanimation.h \
    aboutvic.h \
    datatextfour.h \
    datatextfourc.h \
    datatextfourwhite.h \
    datatextfourred.h \
    endredfour.h \
    datatextfive.h

FORMS += \
        mainwindow.ui \
    aboutvic.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc
