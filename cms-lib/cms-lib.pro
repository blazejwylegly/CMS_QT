#It's a library project, so GUI module is not needed
QT += quick
QT += core
QT += network
QT += core gui sql
QT += sql

#Explicitly specifying the name of the binary output - optional
TARGET = cms-lib

#We want to get library, not app
TEMPLATE = lib

#Triggers shared library symbols export
DEFINES += CMSLIB_LIBRARY

CONFIG += c++14

INCLUDEPATH += source

include(../qmake-target-platform.pri)
include(../qmake-destination-path.pri)

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=  \
    source/administration/Clinic.cpp \
    source/administration/Organiser.cpp \
    source/controllers/adminviewcontroller.cpp \
    source/controllers/loginviewcontroller.cpp \
    source/controllers/maincontroller.cpp \
    source/controllers/menubarcontroller.cpp \
    source/controllers/patientadditioncontroller.cpp \
    source/controllers/patientsdisplaycontroller.cpp \
    source/controllers/patientslistmodel.cpp \
    source/controllers/userviewcontroller.cpp \
    source/data-mngmnt/AccountDAO.cpp \
    source/data-mngmnt/DoctorDAO.cpp \
    source/data-mngmnt/PatientDAO.cpp \
    source/data-mngmnt/SQLAdapter.cpp \
    source/data-mngmnt/SQLManager.cpp \
    source/models/AccountData.cpp \
    source/models/AppUser.cpp \
    source/models/Doctor.cpp \
    source/models/MedicalProcedure.cpp \
    source/models/Patient.cpp \
    source/models/Person.cpp \
    source/models/Registry.cpp \
    source/models/User.cpp \
    source/utility/Encryptor.cpp \
    source/utility/TimeManager.cpp


HEADERS +=  source/cms-lib_global.h \
            source/administration/Clinic.h \
            source/administration/Organiser.h \
            source/controllers/adminviewcontroller.h \
            source/controllers/loginviewcontroller.h \
            source/controllers/maincontroller.h \
            source/controllers/menubarcontroller.h \
            source/controllers/patientadditioncontroller.h \
            source/controllers/patientsdisplaycontroller.h \
            source/controllers/patientslistmodel.h \
            source/controllers/userviewcontroller.h \
            source/data-mngmnt/AccountDAO.h \
            source/data-mngmnt/DAO.h \
            source/data-mngmnt/DoctorDAO.h \
            source/data-mngmnt/PatientDAO.h \
            source/data-mngmnt/SQLAdapter.h \
            source/data-mngmnt/SQLManager.h \
            source/models/AccountData.h \
            source/models/AppUser.h \
            source/models/Doctor.h \
            source/models/MedicalProcedure.h \
            source/models/Patient.h \
            source/models/Person.h \
            source/models/Registry.h \
            source/models/User.h \
            source/utility/Encryptor.h \
            source/utility/TimeManager.h

DESTDIR = $$PWD/../binaries/$$DESTINATION_PATH
OBJECTS_DIR = $$PWD/build/$$DESTINATION_PATH/.obj
MOC_DIR = $$PWD/build/$$DESTINATION_PATH/.moc
RCC_DIR = $$PWD/build/$$DESTINATION_PATH/.qrc
UI_DIR = $$PWD/build/$$DESTINATION_PATH/.ui

message(cms-lib output dir: $${DESTDIR})

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

message(cms-lib project dir: $${PWD})
