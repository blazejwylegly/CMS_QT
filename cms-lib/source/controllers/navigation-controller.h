#ifndef NAVIGATIONCONTROLLER_H
#define NAVIGATIONCONTROLLER_H


#include <QObject>

#include <cms-lib_global.h>
#include <models/patient.h>

namespace cms {
namespace controllers {

class CMSLIBSHARED_EXPORT NavigationController : public QObject{
    Q_OBJECT
public:
    explicit NavigationController(QObject* _parent = nullptr) : QObject(_parent){}

signals:
    void goCreatePatientView();
    void goDashboardView();
    void goEditPatientView(cms::models::Patient* patient);
    void goFindPatientView();
};
}
}
#endif // NAVIGATIONCONTROLLER_H
