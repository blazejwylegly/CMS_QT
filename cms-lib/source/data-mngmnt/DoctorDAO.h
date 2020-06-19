#pragma once
#include "DAO.h"
#include <models/Doctor.h>
#include <string>

class DoctorDAO : public DAO<Doctor>
{
public:
	DoctorDAO() : DAO("pesel, surname, first_name, second_name, children_doctor, work_start, work_end", "doctors") {};
	//bool add(const SQLAdapter<Doctor>& obj) override;
    //bool update(const SQLAdapter<Doctor>& obj1, const SQLAdapter<Doctor>& obj2) override;
	//bool remove(int id) override;
};

