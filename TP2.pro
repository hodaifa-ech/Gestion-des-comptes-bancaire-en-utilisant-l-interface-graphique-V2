QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    OthersFunctions.cpp \
    about.cpp \
    dbConnect.cpp \
    dialog1.cpp \
    dialog2.cpp \
    dialogaccount.cpp \
    dialogconfiguration.cpp \
    dialogconnexion.cpp \
    dialogcreate.cpp \
    dialogcredit.cpp \
    dialogcreditw.cpp \
    dialogdebit.cpp \
    dialogdebitw.cpp \
    dialogdial.cpp \
    dialogloan.cpp \
    dialoglogin.cpp \
    dialognewcount.cpp \
    dialogroot.cpp \
    dialogtransaction.cpp \
    dialogtransfer.cpp \
    dialogtransferw.cpp \
    main.cpp \
    mainwindow0.cpp \
    mediator.cpp

HEADERS += \
    OthersFunctions.h \
    about.h \
    dbConnexion.h \
    dialog1.h \
    dialog2.h \
    dialogaccount.h \
    dialogconfiguration.h \
    dialogconnexion.h \
    dialogcreate.h \
    dialogcredit.h \
    dialogcreditw.h \
    dialogdebit.h \
    dialogdebitw.h \
    dialogdial.h \
    dialogloan.h \
    dialoglogin.h \
    dialognewcount.h \
    dialogroot.h \
    dialogtransaction.h \
    dialogtransfer.h \
    dialogtransferw.h \
    mainwindow0.h \
    mediator.h

FORMS += \
    about.ui \
    dialog1.ui \
    dialog2.ui \
    dialogaccount.ui \
    dialogconfiguration.ui \
    dialogconnexion.ui \
    dialogcreate.ui \
    dialogcredit.ui \
    dialogcreditw.ui \
    dialogdebit.ui \
    dialogdebitw.ui \
    dialogdial.ui \
    dialogloan.ui \
    dialoglogin.ui \
    dialognewcount.ui \
    dialogroot.ui \
    dialogtransaction.ui \
    dialogtransfer.ui \
    dialogtransferw.ui \
    mainwindow0.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    RImages.qrc

DISTFILES += \
    MesImages/Screenshot_20210211-233620.png \
    MesImages/Screenshot_20210211-233649.png \
    MesImages/Screenshot_20210211-233739.png \
    MesImages/Screenshot_20210211-233830.png \
    MesImages/Screenshot_20210211-233939.png \
    MesImages/Screenshot_20210211-234013.png \
    MesImages/Screenshot_20210211-234028.png \
    MesImages/Screenshot_20210211-234326.png \
    MesImages/Screenshot_20210211-234543.png \
    MesImages/Screenshot_20210211-234707.png \
    MesImages/Screenshot_20210211-234801.png
