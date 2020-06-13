#include "userviewcontroller.h"

namespace cms {
namespace controllers {

UserViewController::UserViewController(QQmlApplicationEngine* engine){
    rootObject = engine->rootObjects().first()->findChild<QObject*>("userView");

    patientAdditionController = new PatientAdditionController(engine);

}


UserViewController::~UserViewController(){
    delete patientAdditionController;
}


}
}
