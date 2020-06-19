#pragma once
#include "AccountData.h"
#include <models/MedicalProcedure.h>
#include <models/Patient.h>
#include "administration/Organiser.h"
#include <iostream>
#include <memory>

class AppUser : public AccountData{
public:

    int registerPatient(const cms::models::Patient& obj);
    PatientPtr getPatient(const int& id);
    PatientCont getAllPatients();

    bool reschedule();
    void cancelAppointment();
	int setAppointment(const MedicalProcedure& obj);

	//std::unique_ptr<Patient> registerPatient();
	//void reschedule();
	//void cancler();
	//void retrievePatientData();
	//void setAppointment();
};

