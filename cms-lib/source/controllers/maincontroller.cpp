#include "maincontroller.h"

namespace cms {
namespace controllers {

MainController::MainController(QQmlApplicationEngine* _engine){

    this->engine = _engine;
    this->rootObject = engine->rootObjects().first();
    this->lvc = new LoginViewController(engine);
//    this->menuBarController = new MenuBarController(engine);

    engine->rootContext()->setContextProperty("loginController", lvc);
//    engine->rootContext()->setContextProperty("menuBarController", menuBarController);
}

MainController::~MainController(){
    delete this->lvc;
}

}
}

