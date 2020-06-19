#ifndef ADMINVIEWCONTROLLER_H
#define ADMINVIEWCONTROLLER_H

#include <QObject>

#include <cms-lib_global.h>

#include "userviewcontroller.h"

namespace cms {
namespace controllers {

class CMSLIBSHARED_EXPORT AdminViewController : public UserViewController
{
    Q_OBJECT

private:
    //UserViewController uvc;
    void initialize() override{
        rootObject = engine->rootObjects().first()->findChild<QObject*>("adminView");

    }

public:
    AdminViewController(QQmlApplicationEngine *engine) : UserViewController(engine){
        initialize();
    };

    ~AdminViewController() {

    };


signals:

};

}
}


#endif // ADMINVIEWCONTROLLER_H
