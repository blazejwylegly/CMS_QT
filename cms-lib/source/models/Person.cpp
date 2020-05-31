#include "Person.h"


Person& Person::operator=(Person&& obj)
{
	if (this != &obj) {
		firstName = std::move(obj.firstName);
		secondName = std::move(obj.secondName);
		surname = std::move(obj.surname);
		pesel = std::move(obj.pesel);  
	}
	return *this;
}

void Person::print() const{
	std::cout << "PESEL: " << pesel << "\n";
	std::cout << "surname: " << surname << "\n";
	std::cout << "First name: " << firstName << "\n";
	std::cout << "second name: " << secondName << "\n";
}

/**
0 - equal
<0 - compared string is "lower"
>0 - compared string (this.surname) is "greater"
*/
int Person::compare(const Person& obj) {
	return surname.compare(obj.surname);
}

void to_json(nlohmann::json& j,const Person & obj) {

	j = nlohmann::json{ {"firstName", obj.firstName},
						{"secondName", obj.secondName},
						{"surname", obj.surname},
						{"pesel", obj.pesel}
		};
	}

std::string Person::marshal() const {
	std::string str;
	str += pesel;
	str += (std::string) ",'" += surname;
	str += (std::string) "','" += firstName;
	str += (std::string) "','" += secondName;
	str += (std::string) "'";
	return str;
};
//
//std::unique_ptr<Person> Person::deserialize(MYSQL_ROW& row, unsigned int fieldNum) {
//	if (!row) {
//		return nullptr;
//	}
//	std::string pesel, surname, firstName, secondName;
//	int id;
//	for (int i = 0; i < fieldNum; i++) {
//
//		switch (i) {
//		case 0:
//		{
//			if (row[i] != nullptr) {
//				id = std::atoi(row[i]);
//			}
//			else {
//				return nullptr;
//			}
//			break;
//
//		}
//		case 1:
//		{
//			if (row[i] != nullptr) {
//				pesel = row[i];
//			}
//			else {
//				return nullptr;
//			}
//			break;
//		}
//		case 2:
//		{
//			if (row[i] != nullptr) {
//				surname = row[i];
//			}
//			else {
//				return nullptr;
//			}
//			break;
//		}
//		case 3:
//		{
//			if (row[i] != nullptr) {
//				firstName = row[i];
//			}
//			else {
//				return nullptr;
//			}
//			break;
//		}
//		case 4:
//		{
//			if (row[i] != nullptr) {
//				secondName = row[i];
//			}
//			else {
//				return nullptr;
//			}
//			break;
//		}
//
//		}
//	}
//	return std::make_unique<Person>(pesel, surname, firstName, secondName);	
//}
