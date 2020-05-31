#pragma once
#include "data-mngmnt/PatientDAO.h"
#include "data-mngmnt/DoctorDAO.h"
#include "data-mngmnt/AccountDAO.h"

#include <models/AccountData.h>
#include <models/Doctor.h>
#include <models/MedicalProcedure.h>



typedef std::unique_ptr<cms::models::Patient> PatientPtr;
typedef std::vector<PatientPtr> PatientCont;

typedef std::unique_ptr<Doctor> DoctorPtr;
typedef std::vector<DoctorPtr> DoctorCont;

typedef std::unique_ptr<MedicalProcedure> ProcedurePtr;
typedef std::vector<ProcedurePtr> ProcedureCont;

typedef std::unique_ptr<AccountData> Account;
typedef std::vector<Account> Accounts;


class Organiser
{
private:
	PatientDAO patientDAO;
	DoctorDAO doctorDAO;
    AccountDAO accountDAO;
public:

    Organiser() = default;
	PatientPtr getPatient(const int& id);
	PatientCont getAllPatients();
        int addPatient(const cms::models::Patient& obj);
	bool removePatient(const int& id);
	bool removeAllPatients();
	bool updatePatient();

	DoctorPtr getDoctor(const int& id);
	DoctorCont getAllDoctors();
	int addDoctor(const Doctor& obj);
	bool removeDoctor(const int& id);
	bool removeAllDoctors();
	bool updateDoctor();

	ProcedurePtr getProcedure();
	ProcedureCont getAllProcedures();
	int addProcedure(const MedicalProcedure& obj);
	bool removeProcedure(const int& id);
	bool removeAllProcedures();
	bool rescheduleProcedure();


    Account login(const std::string& login, const std::string& pwd);
    Account login(const int& id, const std::string& pwd);
    Accounts getAllAccounts();
    int addAccount(const AccountData& obj);
    bool removeAccount(const int& id);
//	bool removeAllAccounts();
//	bool updateAccountData();

};


