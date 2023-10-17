QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../meslibrairie/cryptopp/x64/Output/release/ -lcryptlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../meslibrairie/cryptopp/x64/Output/debug/ -lcryptlib

INCLUDEPATH += $$PWD/../meslibrairie/cryptopp
DEPENDPATH += $$PWD/../meslibrairie/cryptopp


win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../meslibrairie/cryptopp/x64/Output/release/cryptlib.lib
win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../meslibrairie/cryptopp/x64/Output/debug/cryptlib.lib

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../meslibrairie/x64/release/ -lchiffrement1
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../meslibrairie/x64/debug/ -lchiffrement1

INCLUDEPATH += $$PWD/../meslibrairie/chiffrement1
DEPENDPATH += $$PWD/../meslibrairie/chiffrement1


win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../meslibrairie/x64/release/chiffrement1.lib
win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../meslibrairie/x64/debug/chiffrement1.lib

RESOURCES += \
    image/image.qrc

DISTFILES +=
