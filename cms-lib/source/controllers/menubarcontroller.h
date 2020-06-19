#ifndef MENUBARCONTROLLER_H
#define MENUBARCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <cms-lib_global.h>

namespace cms {
namespace controllers {

class CMSLIBSHARED_EXPORT MenuBarController : public QObject
{
    Q_OBJECT
private:
    QQmlApplicationEngine* engine {nullptr};
public:
    explicit MenuBarController(QQmlApplicationEngine* _engine);

signals:
    void goDashboardView();
    void loadPatientsDisplay();
    void loadPatientAddition();

};

}
}


#endif // MENUBARCONTROLLER_H
