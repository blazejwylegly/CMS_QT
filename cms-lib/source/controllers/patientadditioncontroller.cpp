#include "patientadditioncontroller.h"


namespace cms {
namespace controllers {

PatientAdditionController::PatientAdditionController(QQmlApplicationEngine* engine){
    this->rootObject = engine->rootObjects().first()->findChild<QObject*>("patientAddition");

    QObject::connect(rootObject, SIGNAL(patientAdditionRequested(QString, QString, QString, QString, int)),
                     this, SLOT(HandlePatientAdditionRequested(QString, QString, QString, QString, int)));
}

void PatientAdditionController::HandlePatientAdditionRequested(QString firstName, QString secondName, QString surname, QString pesel, int docId){
    std::cerr << "Add patient button clicked!" << std::endl;
    std::cerr << "First name: " << firstName.toStdString() << std::endl;
    std::cerr << "Second name: " << secondName.toStdString() << std::endl;
    std::cerr << "Surname: " << surname.toStdString() << std::endl;
    std::cerr << "Pesel: " << pesel.toStdString() << std::endl;
    std::cerr << "docId: " << docId << std::endl;
    if(validateInputs(firstName, secondName, surname, pesel, docId));

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

