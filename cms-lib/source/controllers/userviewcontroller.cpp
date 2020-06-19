#include "userviewcontroller.h"

namespace cms {
namespace controllers {

UserViewController::~UserViewController(){
    delete patientAdditionController;
    delete patientsDisplayController;
    delete menuBarController;
}

void UserViewController::initialize(){
    rootObject = engine->rootObjects().first()->findChild<QObject*>("userView");

    patientAdditionController = new PatientAdditionController(engine);
    patientsDisplayController = new PatientsDisplayController(engine);
    menuBarController = new MenuBarController(engine);
    engine->rootContext()->setContextProperty("menuBarController", menuBarController);
    engine->rootContext()->setContextProperty("patientAdditionController", patientAdditionController);
    engine->rootContext()->setContextProperty("patientsDisplayController", patientsDisplayController);
}

void UserViewController::setConnections(){

}

}
}
