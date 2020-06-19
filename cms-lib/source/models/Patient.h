#pragma once 
#include "Registry.h"
#include "Person.h"

#include <QVariant>
#include <QObject>


namespace cms{
namespace models{

class Patient : public Person, public SQLAdapter<cms::models::Patient>, public QObject
{
private:
    Registry registry;
public:

    //default constructor
    Patient(std::string _pesel = "none", std::string _surname = "none",
        std::string _firstName = "none", std::string _secondName = "none",
        int _doctorInChargeID = -1)
        : Person(_pesel, _surname, _firstName, _secondName), registry(_doctorInChargeID){};

    //copy constructor
    Patient(const Patient& obj) : Person(obj),
        registry(obj.getRegistry()) {};

    //Move assignment constructor
    Patient(Patient&& obj) { *this = std::move(obj); };

    Patient(const Person& obj, const int& _id) : Person(obj), registry(_id) {};

    //Move assignment operator
    Patient& operator=(Patient&& obj);

    int getDocId() const { return registry.getDoctorInChargeID(); };
    Registry getRegistry() const { return registry; };

    //Methods inherited from SQLAdapter
    std::string marshal() const override;
    std::unique_ptr<Patient> deserialize(QSqlQuery& row) override;
    std::vector<std::unique_ptr<Patient>> deserializeAll(QSqlQuery& result) override;

    void print();
};

}
}

