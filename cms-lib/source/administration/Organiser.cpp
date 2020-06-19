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

bool Organiser::removePatient(const std::string &pesel)
{
    return patientDAO.removeWithPesel(pesel);
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

int Organiser::addAccount(const AccountData &obj){
    return accountDAO.add(obj);
}

bool Organiser::removeAccount(const int &id){
    return accountDAO.remove(id);
}
