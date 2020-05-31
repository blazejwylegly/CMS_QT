#ifndef USER_H
#define USER_H

#include <models/AccountData.h>
#include <models/Patient.h>
#include <models/MedicalProcedure.h>

class User : public AccountData
{
public:
    User();

    void registerPatient(const cms::models::Patient& obj);
    void getPatient(const int& id);

    void cancelAppointment();
    void makeAppointment(const MedicalProcedure& obj);
    void reschedule(MedicalProcedure& obj);

};

#endif // USER_H
