QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Commands.cpp \
    ExperimentFileControl.cpp \
    ExperimentSetup.cpp \
    GetUserInfo.cpp \
    MainWindow.cpp \
    SerialControl.cpp \
    main.cpp
    main.cpp \

HEADERS += \
    Commands.h \
    ExperimentFileControl.h \
    ExperimentSetup.h \
    GetUserInfo.h \
    MainWindow.h \
    SerialControl.h

FORMS += \
    ExperimentSetup.ui \
    GetUserInfo.ui \
    MainWindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
