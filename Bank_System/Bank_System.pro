QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    balanceform.cpp \
    bankaccount.cpp \
    cards.cpp \
    changepasses.cpp \
    linklist.cpp \
    loginsigninform.cpp \
    main.cpp \
    newaccountform.cpp \
    transfer.cpp \
    userpanel.cpp \
    users.cpp

HEADERS += \
    balanceform.h \
    bankaccount.h \
    cards.h \
    changepasses.h \
    linklist.h \
    loginsigninform.h \
    newaccountform.h \
    transfer.h \
    userpanel.h \
    users.h

FORMS += \
    balanceform.ui \
    changepasses.ui \
    loginsigninform.ui \
    newaccountform.ui \
    transfer.ui \
    userpanel.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    background.qrc
