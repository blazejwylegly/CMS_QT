#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include <QQmlApplicationEngine>
#include <QObject>

#include <cms-lib_global.h>

namespace cms{
namespace controllers{

class CMSLIBSHARED_EXPORT LoginViewController : public QObject{
    Q_OBJECT
private:
    QObject* loginButton {nullptr};
public:
    explicit LoginViewController(QObject* _parent = nullptr) : QObject(_parent) {}
    LoginViewController(QQmlApplicationEngine* engine){
        QObject* loginScreen = engine->rootObjects().first()->findChild<QObject*>("loginView");
        loginButton = loginScreen->findChild<QObject*>("proceed_button");
        QObject::connect(loginScreen, SIGNAL(loginClicked(QString, QString)), this, SLOT(loginButtonClicked(Qstring, QString)));

    }
signals:
    bool login(QString usr, QString pwd);

public slots:
    void loginButtonClicked(QString user, QString pwd){

    }
};

}
}
#endif // LOGINCONTROLLER_H
