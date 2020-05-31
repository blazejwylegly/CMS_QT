#include "loginviewcontroller.h"

namespace cms {
namespace controllers {

bool LoginViewController::loginButtonClicked(QString user, QString pwd)
{
        std::cerr << "loginButtonClicked " << std::endl;
        return cms::administration::Clinic::login(user.toStdString(), pwd.toStdString());
}



}
}
