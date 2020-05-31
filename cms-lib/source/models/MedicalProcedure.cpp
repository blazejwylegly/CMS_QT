#include "MedicalProcedure.h"

MedicalProcedure::MedicalProcedure() {
	startDate = std::make_unique<tm>();
	TimeManager::initStartDate(startDate.get());

	endDate = std::make_unique<tm>(*startDate);
	TimeManager::initEndDate(startDate.get(), endDate.get());
};

MedicalProcedure::~MedicalProcedure()
{
}

//std::string MedicalProcedure::getPatientID() const {
//	return patientID;
//}

//std::string MedicalProcedure::getDoctorID() const {
//	return doctorID;
//}

//std::string MedicalProcedure::getDescription() const {
//	return description;
//}

//std::string MedicalProcedure::getLocalization() const {
//	return localization;
//}

tm* MedicalProcedure::getStartDate() const {
	return startDate.get();
}

tm* MedicalProcedure::getEndDate() const {
	return endDate.get();
}

double MedicalProcedure::getDuration() {
	return TimeManager::getDifference(startDate.get(), endDate.get());
}




//PRIVATE METHODS


//void MedicalProcedure::reschedule() {
//	std::cout << "Rescheduling appointment date" << std::endl;
//	
//	int diff = difftime(mktime(endDate), mktime(startDate));
//	std::cout << diff << std::endl;
//	initStartDate();
//	endDate->tm_min = startDate->tm_min + diff % 61;
//	endDate->tm_hour = startDate->tm_min + diff % 3601;
//	printDate(endDate);
//}

//void MedicalProcedure::to_json(nlohmann::json& j,const MedicalProcedure& medProc) {
//	j = nlohmann::json{ {"doctor_id", medProc.doctorID},
//						{"patient_id", medProc.patientID},
//						{"localization", medProc.localization} 	};
//}
