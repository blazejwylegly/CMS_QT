QT += testlib
QT -= gui

TARGET = client_tests

CONFIG += qt console warn_on depend_includepath testcase
CONFIG += c++14
CONFIG += console
CONFIG -= app_bundle


TEMPLATE = app

INCLUDEPATH += source

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

SOURCES +=  source/models/client_tests.cpp

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

LIBS += -L$$PWD/../binaries/$$DESTINATION_PATH -lcms-lib
