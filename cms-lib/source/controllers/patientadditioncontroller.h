#ifndef PATIENTADDITIONCONTROLLER_H
#define PATIENTADDITIONCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>

#include <cms-lib_global.h>

#include "models/Patient.h"

namespace cms {
namespace controllers {

class CMSLIBSHARED_EXPORT PatientAdditionController : public QObject
{
    Q_OBJECT
private:
    QObject* rootObject {nullptr};
public:
    explicit PatientAdditionController(QQmlApplicationEngine *parent = nullptr);

public slots:
    void HandlePatientAdditionRequested(QString, QString, QString, QString, int);

};

}
}



#endif // PATIENTADDITIONCONTROLLER_H