QT       += core gui
QT       += sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deleteclient.cpp \
    functions.cpp \
    insertclient.cpp \
    main.cpp \
    mainwindow.cpp \
    tableviewer.cpp \
    updateclient.cpp

HEADERS += \
    deleteclient.h \
    functions.h \
    headers.h \
    insertclient.h \
    mainwindow.h \
    tableviewer.h \
    updateclient.h

FORMS += \
    deleteclient.ui \
    insertclient.ui \
    mainwindow.ui \
    tableviewer.ui \
    updateclient.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
