#include "maincontroller.h"

namespace cms {
namespace controllers {

MainController::MainController(QQmlApplicationEngine* _engine){
    this->engine = _engine;
    this->rootObject = engine->rootObjects().first();
    this->lvc = new cms::controllers::LoginViewController(_engine);
    engine->rootContext()->setContextProperty("loginController", lvc);
}

MainController::~MainController(){
    delete this->lvc;
}

}
}

