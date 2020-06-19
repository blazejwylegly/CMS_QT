#ifndef BANK_H
#define BANK_H

#include <models/AccountData.h>

#include <administration/Organiser.h>

namespace cms {
namespace administration {

class Clinic
{
private:
    static Organiser organiser;
    static std::shared_ptr<AccountData> currentUser;
public:
    Clinic();
    static void initialize();
    static bool login(const std::string& login, const std::string& pwd);
    static bool isAdminLogged();

//    static std::shared_ptr<AccountData> getCurrentUser();

    static PatientCont getAllPatients();
    static int addPatient(const std::string &firstName,
                          const std::string &secondName,
                          const std::string &surname,
                          const std::string &pesel,
                          const int &docId);
};

}
}


#endif // BANK_H
