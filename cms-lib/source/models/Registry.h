#pragma once
#include "Doctor.h"

class Registry
{
private:
	int doctorInChargeID;
	//List<MedicalProcedure> history;
public:
	Registry(int _doctorInChargeID = -1) : doctorInChargeID(_doctorInChargeID) {};
	int getDoctorInChargeID() const { return doctorInChargeID; };
	
};

