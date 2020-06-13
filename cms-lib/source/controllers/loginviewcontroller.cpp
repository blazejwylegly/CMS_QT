#include "loginviewcontroller.h"

namespace cms {
namespace controllers {

void LoginViewController::loginButtonClicked(QString user, QString pwd)
{
    if(cms::administration::Clinic::login(user.toStdString(), pwd.toStdString())){
        loadUserView(); return;
        if(cms::administration::Clinic::isAdminLogged()) {  return; }
        else { emit userLoginSuccessful(); return; }
    }
    emit loginFailed();

}

LoginViewController::LoginViewController(QQmlApplicationEngine* _engine){

    this->engine = _engine;
    this->rootObject = engine->rootObjects().first()->findChild<QObject*>("loginView");

    loginButton = rootObject->findChild<QObject*>("proceed_button");
    std::cerr << loginButton << std::endl;

    QObject::connect(rootObject, SIGNAL(loginClicked(QString, QString)), this, SLOT(loginButtonClicked(QString, QString)));


}

LoginViewController::~LoginViewController(){
    delete uvc;
}

void LoginViewController::loadAdminView(){
    //uvc = new UserViewController(engine);
    emit adminLoginSuccessful();
}

void LoginViewController::loadUserView(){
    //uvc = new UserViewController(engine);
    emit userLoginSuccessful();
}


}
}
