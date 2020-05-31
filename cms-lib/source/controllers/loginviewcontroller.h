#ifndef LOGINVIEWCONTROLLER_H
#define LOGINVIEWCONTROLLER_H

#include <QQmlApplicationEngine>
#include <QObject>

#include <cms-lib_global.h>

#include <administration/Clinic.h>

namespace cms{
namespace controllers{

class CMSLIBSHARED_EXPORT LoginViewController : public QObject{
    Q_OBJECT
private:
    QObject* loginButton {nullptr};
public:
    explicit LoginViewController(QObject* _parent = nullptr) : QObject(_parent) {}

    LoginViewController(QQmlApplicationEngine* engine){
        QObject* loginView = engine->rootObjects().first()->findChild<QObject*>("loginView");
        std::cerr << "login view: " << loginView << std::endl;
        loginButton = loginView->findChild<QObject*>("proceed_button");
        QObject::connect(loginView, SIGNAL(loginClicked(QString, QString)), this, SLOT(loginButtonClicked(QString, QString)));

    }
//signals:
//    bool login(QString usr, QString pwd);

public slots:
    bool loginButtonClicked(QString user, QString pwd);
};

}
}
#endif // LOGINVIEWCONTROLLER_H
