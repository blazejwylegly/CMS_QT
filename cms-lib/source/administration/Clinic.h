#ifndef BANK_H
#define BANK_H

#include <models/AccountData.h>

#include "Organiser.h"

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
};

}
}


#endif // BANK_H
