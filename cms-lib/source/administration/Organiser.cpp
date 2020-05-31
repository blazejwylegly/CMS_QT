#include "Organiser.h"

#include <iostream>

PatientPtr Organiser::getPatient(const int& id)
{
    return patientDAO.get(id);
}

PatientCont Organiser::getAllPatients()
{
    return patientDAO.getAll();
}

int Organiser::addPatient(const cms::models::Patient& obj)
{
    return patientDAO.add(obj);
}

bool Organiser::removePatient(const int& id)
{
    return patientDAO.remove(id);
}

//bool Organiser::removeAllPatients()
//{
//	return patientDAO.removeAll();
//}

DoctorPtr Organiser::getDoctor(const int& id)
{
    return doctorDAO.get(id);
}

DoctorCont Organiser::getAllDoctors()
{
    return doctorDAO.getAll();
}

int Organiser::addDoctor(const Doctor& obj)
{
    return doctorDAO.add(obj);
}

bool Organiser::removeDoctor(const int& id)
{
    return doctorDAO.remove(id);
}

//bool Organiser::removeAllDoctors()
//{
//	return doctorDAO.removeAll();
//}

Account Organiser::login(const std::string& login, const std::string& pwd){
    Account ptr = accountDAO.get(login);
    if(ptr != nullptr && ptr->authenticate(pwd)){
        return ptr;
    }else{
        return nullptr;
    }
}

//Account Organiser::login(const int &id, const std::string &pwd){
//    Account ptr = accountDAO.get(id);
//    if(ptr != nullptr && ptr->authenticate(pwd)){
//        return ptr;
//    }else{
//        return nullptr;
//    }
//}

Accounts Organiser::getAllAccounts(){
    return accountDAO.getAll();
}

int Organiser::addAccount(const AccountData &obj){

//    if(accountDAO.get(obj.getLogin()) == nullptr){
//        return accountDAO.add(obj);
//    }else{
//        return -1;
//    }
    return accountDAO.add(obj);

}
