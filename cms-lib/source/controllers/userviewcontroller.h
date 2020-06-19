#ifndef USERVIEWCONTROLLER_H
#define USERVIEWCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include <cms-lib_global.h>

#include "patientadditioncontroller.h"
#include "patientsdisplaycontroller.h"

#include "menubarcontroller.h"
namespace cms {
namespace controllers{

class CMSLIBSHARED_EXPORT UserViewController : public QObject
{
    Q_OBJECT

protected:
    QQmlApplicationEngine* engine {nullptr};
    QObject* rootObject {nullptr};

    PatientAdditionController* patientAdditionController {nullptr};
    PatientsDisplayController* patientsDisplayController {nullptr};
    MenuBarController* menuBarController{nullptr};

    virtual void initialize();
    virtual void setConnections();

public:
    UserViewController(QQmlApplicationEngine *engine){
        this->engine = engine;
        this->initialize();
        this->setConnections();
    }

    ~UserViewController();
signals:

};

}
}


#endif // USERVIEWCONTROLLER_H
