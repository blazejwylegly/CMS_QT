#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QScopedPointer>
#include <QString>


#include <QQmlContext>

#include <cms-lib_global.h>
#include <controllers/navigation-controller.h>
#include <controllers/commandcontroller.h>
#include <controllers/loginviewcontroller.h>

namespace cms{
namespace controllers{

class CMSLIBSHARED_EXPORT MasterController : public QObject
{
    Q_OBJECT
    //Defining QML property so we can access initialMessage member from QML
    //QML will refer to this member as ui_initialMessage
    Q_PROPERTY(QString ui_initialMessage READ initialMessage CONSTANT)
    Q_PROPERTY(cms::controllers::NavigationController* ui_navigationController READ navigationController CONSTANT )
    Q_PROPERTY(cms::controllers::CommandController* ui_commandController READ commandController CONSTANT)
    Q_PROPERTY(cms::controllers::LoginViewController* ui_loginController READ loginController CONSTANT)
public:

    explicit MasterController(QObject *parent = nullptr);
    ~MasterController();

    NavigationController* navigationController();
    CommandController* commandController();
    LoginViewController* loginController();

    const QString& initialMessage() const;

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;


};

}
}


#endif // MASTERCONTROLLER_H
