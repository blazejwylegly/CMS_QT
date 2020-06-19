#include "patientadditioncontroller.h"


namespace cms {
namespace controllers {

PatientAdditionController::PatientAdditionController(QQmlApplicationEngine* engine){
    this->rootObject = engine->rootObjects().first()->findChild<QObject*>("patientAddition");

    QObject::connect(rootObject, SIGNAL(patientAdditionRequested(QString, QString, QString, QString, int)),
                     this, SLOT(HandlePatientAdditionRequested(QString, QString, QString, QString, int)));
}

void PatientAdditionController::HandlePatientAdditionRequested(QString firstName, QString secondName, QString surname, QString pesel, int docId){

    if(validateInputs(firstName, secondName, surname, pesel, docId)){
        int addAttempt = Clinic::addPatient(firstName.toStdString(),
                                            secondName.toStdString(),
                                            surname.toStdString(),
                                            pesel.toStdString(),
                                            docId);
        if(addAttempt != -1){
            emit additionSuccessful();
            return;
        }

        emit additionFailed(); return;
    }
    emit invalidInput(); return;


}

bool PatientAdditionController::validateInputs(QString firstName, QString secondName, QString surname, QString pesel, int docId){
    const std::regex stringRegex ("[a-zA-Z]+");
    const std::regex peselRegex ("\\d{11}");

    if(!std::regex_match(firstName.toStdString(), stringRegex)) return false;
    if(!std::regex_match(secondName.toStdString(), stringRegex)) return false;
    if(!std::regex_match(surname.toStdString(), stringRegex)) return false;
    if(!std::regex_match(pesel.toStdString(), peselRegex)) return false;
    return true;



}

}
}

