#include "loginviewcontroller.h"

namespace cms {
namespace controllers {

void LoginViewController::loginButtonClicked(QString user, QString pwd)
{
    std::cerr << "loginButtonClicked " << std::endl;
            if(cms::administration::Clinic::login(user.toStdString(), pwd.toStdString())){
                emit loginSuccessful(); return;
            }
            emit loginFailed();

}
}
}
