#pragma once
#include "Person.h"
#include "utility/TimeManager.h"
#include <memory.h>
#include <string>

#include <QVariant>
#include <QTime>
#include <QtSql/QSqlField>
#include <QDebug>
#include "3rdparty/include/nlohmann/json.hpp"

class Doctor : public Person, public SQLAdapter<Doctor>
{
private:
	bool childrenDoctor;
	std::unique_ptr<tm> startTime;
	std::unique_ptr<tm> endTime;	
public:
	Doctor() : childrenDoctor(false), startTime(nullptr), endTime(nullptr) {};

	Doctor(std::string _pesel, std::string _surname, std::string _firstName,
		std::string _secondName, bool _childrenDoctor = false,
		std::unique_ptr<tm> _startTime = nullptr, std::unique_ptr<tm> _endTime = nullptr)
		: Person(_pesel, _surname, _firstName, _secondName), childrenDoctor(_childrenDoctor),
		startTime(std::move(_startTime)), endTime(std::move(_endTime)){

		if (startTime == nullptr) {
			startTime = std::make_unique<tm>();
			std::cout << "Initializing start time" << std::endl;
			TimeManager::initStartTime(startTime.get());
		}
		
		if (endTime == nullptr) {
			endTime = std::make_unique<tm>();
			std::cout << "Initializing end time" << std::endl;
			TimeManager::initEndTime(startTime.get(), endTime.get());
		}
		

	}

	

	//Copy constructor
	Doctor(const Doctor& _doctor) : 
		Person(_doctor.getFirstName(), _doctor.getSecondName(),
		_doctor.getSurname(), _doctor.getPesel()), childrenDoctor(_doctor.childrenDoctor){};
															  
	//Move assignment constructor
	Doctor(Doctor&& _doctor) { *this = std::move(_doctor); };

	//Move assignment operator
	Doctor& operator=(Doctor&& obj);

	~Doctor() = default;

	void print();

	bool getChildrenDoctor() const;
	tm* getStartTime() const;
	tm* getEndTime() const;

	friend void to_json(nlohmann::json& j, const Doctor& obj);

	std::string marshal() const override;
    std::unique_ptr<Doctor> deserialize(QSqlQuery& row) override;
    std::vector<std::unique_ptr<Doctor>> deserializeAll(QSqlQuery& result) override;
};

