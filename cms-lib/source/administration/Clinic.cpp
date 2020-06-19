#include "Clinic.h"

namespace cms {
namespace administration {

 Organiser Clinic::organiser;
std::shared_ptr<AccountData> Clinic::currentUser = nullptr;

Clinic::Clinic()
{
    initialize();

}

void Clinic::initialize(){

}

bool Clinic::login(const std::string& login, const std::string& pwd){
    currentUser = organiser.login(login, pwd);
    return (bool)currentUser;
}

bool Clinic::isAdminLogged(){
    return currentUser->isAdmin();
}

//std::shared_ptr<AccountData> Clinic::getCurrentUser(){
//    return std::make_shared<AccountData>(currentUser);
//}

PatientCont Clinic::getAllPatients(){
    PatientCont patients;
    if(currentUser) return organiser.getAllPatients();
    return patients;
}

int Clinic::addPatient(const std::string &firstName,
                       const std::string &secondName,
                       const std::string &surname,
                       const std::string &pesel,
                       const int &docId){
    if(currentUser) return organiser.addPatient(cms::models::Patient(pesel, surname, firstName, secondName, docId));
    return -1;
}

void Clinic::deletePatient(const int &id){
    if(currentUser){
        organiser.removePatient(id);
    }
}

void Clinic::deletePatient(const std::string &peselNumber)
{
    organiser.removePatient(peselNumber);
}

}
}


