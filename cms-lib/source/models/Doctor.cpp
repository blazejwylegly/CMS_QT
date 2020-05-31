#include "Person.h"
#include "Doctor.h"

//const std::string Doctor::columns[numColumns] = {"pesel", "id", "surname", "first_name", "second_name", "work_start", "work_end"};

//Move assignment operator
Doctor& Doctor::operator=(Doctor&& obj) {
	if (this != &obj) {
		Person::operator=(std::move(obj));
		childrenDoctor = obj.childrenDoctor;
		
		obj.childrenDoctor = false;
	}
	return *this;
}

void Doctor::print(){
	Person::print();
	std::cout << "Children doctor: " << childrenDoctor << std::endl;
	std::cout << "Work start time: ";
	TimeManager::printTime(startTime.get());
    std::cout << "Work end time: ";
	TimeManager::printTime(endTime.get());
}



bool Doctor::getChildrenDoctor() const{
	return childrenDoctor;
};

tm* Doctor::getStartTime() const {
	return startTime.get();
}

tm* Doctor::getEndTime() const {
	return endTime.get();
}

void to_json(nlohmann::json& j,const Doctor& obj) {
	to_json(j, dynamic_cast<const Person&>(obj));
	j["childrenDoctor"] = obj.getChildrenDoctor();
}

std::string Doctor::marshal() const {
	std::string str = Person::marshal();
	str.append(",");
	if (childrenDoctor) {
		str.append("1");
	}
	else {
		str.append("0");
	}
	str.append(",'");
	str.append(TimeManager::prettyTimePrinting(startTime.get()));
	str.append("','");
	str.append(TimeManager::prettyTimePrinting(endTime.get()));
	str.append("'");
	return str;
}

std::unique_ptr<Doctor> Doctor::deserialize(QSqlQuery& row)
{
    if(row.isValid()){
        std::string pesel, surname, firstName, secondName;
        bool childrenDoctor;
        std::unique_ptr<tm> workStart;
        std::unique_ptr<tm> workEnd;

        pesel = row.value(1).toString().toStdString();
        surname = row.value(2).toString().toStdString();
        firstName = row.value(3).toString().toStdString();
        secondName = row.value(4).toString().toStdString();
        childrenDoctor = row.value(5).toBool();

        workStart = TimeManager::parseTime(row.value(6).toString().toStdString());
        workEnd = TimeManager::parseTime(row.value(7).toString().toStdString());

        return std::make_unique<Doctor>(pesel, surname, firstName, secondName, childrenDoctor, std::move(workStart), std::move(workEnd));
    }else{
        return nullptr;
    }

}

std::vector<std::unique_ptr<Doctor>> Doctor::deserializeAll(QSqlQuery& result) {
    std::vector<std::unique_ptr<Doctor>> doctors;
    if(result.isActive()){
        while(result.next()){
            doctors.push_back(deserialize(result));
        }
    }
    return doctors;
}
