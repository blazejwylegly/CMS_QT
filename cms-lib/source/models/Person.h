#pragma once
#include "data-mngmnt/SQLAdapter.h"
#include <string>
#include <iostream>
#include <fstream>
#include "3rdparty/include/nlohmann/json.hpp"

typedef unsigned int person_ID_type;

class Person
{

private:
	std::string pesel;
	std::string surname;
	std::string firstName;
	std::string secondName;
protected:
	std::string marshal() const;
public:

	Person(std::string _pesel = "none", std::string _surname = "none",
		std::string _firstName = "none", std::string _secondName = "none")
		: pesel(_pesel), surname(_surname),
		firstName(_firstName), secondName(_secondName){
	};

	Person(Person&& obj) : pesel(std::move(obj.pesel)),
		surname(std::move(obj.surname)), firstName(std::move(obj.firstName)),
		secondName(std::move(obj.secondName)) {};

	Person(const Person& obj) : pesel(obj.pesel),surname(obj.surname),
		firstName(obj.firstName), secondName(obj.secondName) {};

	virtual Person& operator=(Person&& obj);

	std::string getPesel() const { return pesel; };
	std::string getSurname() const { return surname; };
	std::string getFirstName() const { return firstName; };
	std::string getSecondName() const { return secondName; };
	std::string getFullName() const { return firstName + " " + secondName + " " + surname; };

	int compare(const Person& obj);
	virtual void print() const;

	friend void to_json(nlohmann::json& j, const Person& obj);

};																		  

