#include "patientadditioncontroller.h"


namespace cms {
namespace controllers {

PatientAdditionController::PatientAdditionController(QQmlApplicationEngine* engine){
    this->rootObject = engine->rootObjects().first()->findChild<QObject*>("patientAddition");

    std::cerr << rootObject << std::endl;
    QObject::connect(rootObject, SIGNAL(patientAdditionRequested(QString, QString, QString, QString, int)),
                     this, SLOT(HandlePatientAdditionRequested(QString, QString, QString, QString, int)));
}

void PatientAdditionController::HandlePatientAdditionRequested(QString firstName, QString secondName, QString surname, QString pesel, int docId){
    std::cerr << "Add patient button clicked!" << std::endl;
}

}
}

