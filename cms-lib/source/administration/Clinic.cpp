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

PatientCont Clinic::getAllPatients(){
    return organiser.getAllPatients();
}

}
}


