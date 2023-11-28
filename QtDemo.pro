#-------------------------------------------------
#
# Project created by QtCreator 2023-11-27T15:43:45
#
#-------------------------------------------------

#引入Qt的模块，core gui
QT       += core gui widgets

#生成最终文件的文件名，可执行文件exe
TARGET = QtDemo
#项目类型，生成什么类型的文件，可执行程序还是库文件
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

#要编译的源文件列表
SOURCES += \
        main.cpp \
        mainwindow.cpp \
        mywindow.cpp

#要编译的头文件列表
HEADERS += \
        mainwindow.h \
        mywindow.h

#要编译的ui文件列表
FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
