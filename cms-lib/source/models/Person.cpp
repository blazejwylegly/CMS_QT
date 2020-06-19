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
    str.append("\"").append(pesel).append("\"");
	str += (std::string) ",'" += surname;
	str += (std::string) "','" += firstName;
	str += (std::string) "','" += secondName;
	str += (std::string) "'";
	return str;
};
