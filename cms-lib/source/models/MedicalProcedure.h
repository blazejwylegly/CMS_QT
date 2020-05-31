#pragma once
#include "Doctor.h"	
#include "utility/TimeManager.h"

#include "time.h"
//class Patient;

class MedicalProcedure
{
private:

	//Unique pointers, because medical procedure is the
	//ONLY OWNER OF dates
	std::unique_ptr<tm> startDate;
	std::unique_ptr<tm> endDate;
	/*std::string day;
	std::string startAt;
	std::string endAt;*/
    int patientID;
    int doctorID;
//	std::string description;
//	std::string localization;


	//void initStartDate();
	//void initEndDate();

public:

	MedicalProcedure();
	~MedicalProcedure();

	std::string getPatientID() const;
	std::string getDoctorID() const;
	std::string getDescription() const;
	std::string getLocalization() const;

	//Getters return raw pointers (observing pointers -
	// pointers which do not keep object alive)
	tm* getStartDate () const;
	tm* getEndDate () const;

	double getDuration();

	//void printDate(const tm* date);
	//void reschedule();

	void to_json(nlohmann::json& obj, const MedicalProcedure& medProc);

};

