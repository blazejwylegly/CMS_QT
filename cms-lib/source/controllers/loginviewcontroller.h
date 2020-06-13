#ifndef LOGINVIEWCONTROLLER_H
#define LOGINVIEWCONTROLLER_H

#include <QQmlApplicationEngine>
#include <QObject>

#include <cms-lib_global.h>

#include <administration/Clinic.h>

#include "userviewcontroller.h"

namespace cms{
namespace controllers{

class CMSLIBSHARED_EXPORT LoginViewController : public QObject{
    Q_OBJECT
private:

    QObject* rootObject {nullptr};
    QObject* loginButton {nullptr};

    QQmlApplicationEngine* engine {nullptr};

    UserViewController* uvc {nullptr};

    void loadAdminView();
    void loadUserView();
public:

    LoginViewController(QQmlApplicationEngine* _engine);
    ~LoginViewController();

public slots:
    void loginButtonClicked(QString user, QString pwd);

signals:
    void userLoginSuccessful();
    void adminLoginSuccessful();
    void loginFailed();
};

}
}
#endif // LOGINVIEWCONTROLLER_H
