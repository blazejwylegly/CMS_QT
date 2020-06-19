#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QQmlContext>

#include <cms-lib_global.h>

#include "loginviewcontroller.h"
#include "menubarcontroller.h"

namespace cms {
namespace controllers {

class CMSLIBSHARED_EXPORT MainController : public QObject
{
    Q_OBJECT

private:
    QObject* rootObject {nullptr};
    QQmlApplicationEngine* engine {nullptr};
    LoginViewController* lvc {nullptr};
    MenuBarController* menuBarController {nullptr};

public:
    MainController(QQmlApplicationEngine* _engine);
    ~MainController();
};

}
}



#endif // MAINCONTROLLER_H
