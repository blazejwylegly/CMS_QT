#include <models/Patient.h>


namespace cms {
namespace models {

Patient& Patient::operator=(Patient&& obj) {
    if (this != &obj) {
        Person::operator=(std::move(obj));
        registry = obj.registry;

    }
    std::cout << "Pacjent" << std::endl;
    this->print();
    return *this;
}

std::string Patient::marshal() const {

    std::string values = Person::marshal();
    values += ",";
    if (registry.getDoctorInChargeID() == -1) {
        values += "NULL";
    }
    else {
        values += registry.getDoctorInChargeID();
    }
    return values;
}

void Patient::print() {
    Person::print();
    std::cout << "Doctor in charge id: " << registry.getDoctorInChargeID() << std::endl;
}


std::unique_ptr<Patient> Patient::deserialize(QSqlQuery& row) {

    if(row.isValid()){

        std::string pesel, surname, firstName, secondName;
        int doctorId;

        pesel = row.value(1).toString().toStdString();
        surname = row.value(2).toString().toStdString();
        firstName = row.value(3).toString().toStdString();
        secondName = row.value(4).toString().toStdString();

        if (row.value(5).isNull()) {
           doctorId = -1;
        }
        else {
           doctorId = row.value(5).toInt();
        }

        return std::make_unique<Patient>(pesel, surname, firstName, secondName, doctorId);

    }else{
        return nullptr;
    }

}

std::vector<std::unique_ptr<Patient>> Patient::deserializeAll(QSqlQuery& result) {

    std::vector<std::unique_ptr<Patient>> patients;

    if(result.isActive()){

        while(result.next()){
             patients.push_back(deserialize(result));
        }
    }

    return patients;
}

}
}




