#include "userviewcontroller.h"

namespace cms {
namespace controllers {

UserViewController::UserViewController(QQmlApplicationEngine *engine){
    rootObject = engine->rootObjects().first()->findChild<QObject*>("userViewController");
    patientAdditionController = new PatientAdditionController();

}


UserViewController::~UserViewController(){
    delete patientAdditionController;
}


}
}
