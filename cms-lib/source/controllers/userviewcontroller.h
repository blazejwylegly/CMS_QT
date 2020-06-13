#ifndef USERVIEWCONTROLLER_H
#define USERVIEWCONTROLLER_H

#include <QObject>

#include "patientadditioncontroller.h"

namespace cms {
namespace controllers{

class UserViewController : public QObject
{
    Q_OBJECT

private:
    QObject* rootObject;
    PatientAdditionController* patientAdditionController {nullptr};
public:
    explicit UserViewController(QQmlApplicationEngine *engine);
    ~UserViewController();
signals:

};

}
}


#endif // USERVIEWCONTROLLER_H
