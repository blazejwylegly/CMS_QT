#include "loginviewcontroller.h"

namespace cms {
namespace controllers {



void LoginViewController::loginButtonClicked(QString user, QString pwd)
{
    using cms::administration::Clinic;
    if(Clinic::login(user.toStdString(), pwd.toStdString())){

        if(Clinic::isAdminLogged()) {loadAdminView(); return;}
        loadUserView(); return;

    }
    emit loginFailed();

}

LoginViewController::LoginViewController(QQmlApplicationEngine* _engine){

    this->engine = _engine;
    this->rootObject = engine->rootObjects().first()->findChild<QObject*>("loginView");

    this->loginButton = rootObject->findChild<QObject*>("proceed_button");

    QObject::connect(rootObject, SIGNAL(loginClicked(QString, QString)), this, SLOT(loginButtonClicked(QString, QString)));


}

LoginViewController::~LoginViewController(){
    if(avc) delete avc;
    if(uvc) delete uvc;
}

void LoginViewController::loadAdminView(){
    emit adminLoginSuccessful();
    avc = new AdminViewController(engine);


}

void LoginViewController::loadUserView(){
    emit userLoginSuccessful();
    uvc = new UserViewController(engine);
}


}
}
