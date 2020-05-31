#include "Clinic.h"

namespace cms {
namespace administration {

Organiser Clinic::organiser;
std::unique_ptr<AccountData> Clinic::currentUser = nullptr;

Clinic::Clinic()
{

}

void Clinic::initialize(){

}


}
}


