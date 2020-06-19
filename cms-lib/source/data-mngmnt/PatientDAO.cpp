#include "PatientDAO.h"
//
//std::unique_ptr<Person> PatientDAO::get(const std::string& surname)
//{
//	return std::unique_ptr<Person>();
//}
//
//std::vector<Patient> PatientDAO::getAll()
//{
//	return std::vector<Patient>();
//}
//
//bool PatientDAO::add(const SQLAdapter<Patient>& obj)
//{
//	std::string query = "INSERT INTO ";
//	query.append(tableName).append("(");
//	query.append(columns).append(")\n").append(" VALUES (");
//	query.append(obj.marshal()).append(" )");
//	return SQLManager::executeInsert(query);
//}

//bool PatientDAO::update(const SQLAdapter<Patient>& oldData, const SQLAdapter<Patient>& newData)
//{
//	return false;
//}

//bool PatientDAO::remove(int id)
//{
//	return false;
//}

bool PatientDAO::removeWithPesel(const std::string &pesel)
{
    std::string query = "DELETE FROM ";
    query.append(tableName).append(" WHERE PESEL = ");
    query.append(pesel);
    return SQLManager::executeRemoval(query.c_str());
}
