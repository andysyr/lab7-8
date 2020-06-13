QT += gui sql widgets core
CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        ../googletest-master/googletest/src/gtest-all.cc \
        ../googletest-master/googletest/src/gtest-death-test.cc \
        ../googletest-master/googletest/src/gtest-filepath.cc \
        ../googletest-master/googletest/src/gtest-matchers.cc \
        ../googletest-master/googletest/src/gtest-port.cc \
        ../googletest-master/googletest/src/gtest-printers.cc \
        ../googletest-master/googletest/src/gtest-test-part.cc \
        ../googletest-master/googletest/src/gtest-typed-test.cc \
        ../googletest-master/googletest/src/gtest.cc \
        databaselologic.cpp \
        main.cpp \
        mainwindow.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    lab7.pro

FORMS += \
    mainwindow.ui

DISTFILES += \
    lab7-8.pro.user

HEADERS += \
    databaselogic.h \
    mainwindow.h

INCLUDEPATH += \
    $$PWD/../googletest-master/googletest \
    $$PWD/../googletest-master/googletest/include \
    $$PWD/../googletest-master/googlemock \
    $$PWD/../googletest-master/googlemock/include
