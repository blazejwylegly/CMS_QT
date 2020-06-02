#include "mastercontroller.h"

namespace cms{
namespace controllers{

class MasterController::Implementation{
public:
    Implementation(MasterController* _masterController) : masterController(_masterController){
        navigationController = new NavigationController(masterController);
        commandController = new CommandController(masterController);
        loginController = new LoginViewController(masterController);
    }

    MasterController* masterController {nullptr};
    NavigationController* navigationController {nullptr};
    CommandController* commandController {nullptr};
    LoginViewController* loginController {nullptr};


    QString initialMessage = "This is MasterController";
};

MasterController::MasterController(QObject *parent) : QObject(parent)
{
    implementation.reset(new Implementation(this));
}

MasterController::~MasterController(){

}

NavigationController* MasterController::navigationController(){
    return implementation->navigationController;
}

CommandController* MasterController::commandController(){
    return implementation->commandController;
}

LoginViewController* MasterController::loginController(){
    return implementation->loginController;
}

const QString& MasterController::initialMessage() const{
    return implementation->initialMessage;
}



}
}
