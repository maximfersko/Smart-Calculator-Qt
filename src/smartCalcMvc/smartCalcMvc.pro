QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controller/controller.cc \
    model/deposit.cc \
    view/depositcalc.cpp \
    model/calculate.cc \
    model/creditModel.cc \
    model/graphBuilder.cc \
    model/parser.cc \
    model/validator.cc \
    view/credit.cpp \
    view/dialoggetx.cpp \
    view/drawplot.cpp \
    view/main.cpp \
    view/mainwindow.cpp \
    qcustomplot.cpp

HEADERS += \
    controller/controller.h \
    model/deposit.h \
    view/depositcalc.h \
    model/creditModel.h \
    model/smartCalc.h \
    view/credit.h \
    view/dialoggetx.h \
    view/drawplot.h \
    view/mainwindow.h \
    qcustomplot.h

FORMS += \
    view/depositcalc.ui \
    view/credit.ui \
    view/dialoggetx.ui \
    view/drawplot.ui \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
