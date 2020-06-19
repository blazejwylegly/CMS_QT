#include "patientsdisplaycontroller.h"

namespace cms {
namespace controllers {

void PatientsDisplayController::initialize(){

}

void PatientsDisplayController::setConnections(){
    QObject::connect(searchBar, SIGNAL(doSearch(QString)), this, SLOT(searchButtonClicked(QString)));
}

PatientsDisplayController::PatientsDisplayController(QQmlApplicationEngine* _engine){
    this->engine = _engine;
    this->rootObject = engine->rootObjects().first()->findChild<QObject*>("patientsDisplay");

    this->searchButton = rootObject->findChild<QObject*>("searchButton");
    this->searchBar = rootObject->findChild<QObject*>("searchBar");
    setConnections();

}

void PatientsDisplayController::searchButtonClicked(QString searchText){
}

}
}
