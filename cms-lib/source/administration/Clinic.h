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
    static std::unique_ptr<AccountData> currentUser;
public:
    Clinic();
    static void initialize();

    static bool login(const std::string& login, const std::string& pwd){
        std::cerr << login << std::endl;
        std::cerr << pwd << std::endl;
        currentUser = organiser.login(login, pwd);
        if(currentUser != nullptr){
            std::cerr << "Logged in" << std::endl;
        }
        return (bool)currentUser;
    }
};

}
}


#endif // BANK_H
