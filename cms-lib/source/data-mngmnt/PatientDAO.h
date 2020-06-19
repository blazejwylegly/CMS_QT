#pragma once
#include "SQLManager.h"
#include <models/Patient.h>
#include "DAO.h"
#include <string>
#include <memory>
#include <iostream>

typedef std::unique_ptr<cms::models::Patient> PatientPtr;
typedef std::vector<PatientPtr> PatientsColl;

class PatientDAO : public DAO <cms::models::Patient>
{
public:

	PatientDAO(): DAO("pesel, surname, first_name, second_name, doctor_in_charge_id", "patients") {};

    bool removeWithPesel(const std::string &pesel);
	//bool add(const SQLAdapter<Patient>& obj) override;
    //bool update(const SQLAdapter<Patient>& oldData, const SQLAdapter<Patient>& newData) override;
    //bool remove(int id) override;
	
};


