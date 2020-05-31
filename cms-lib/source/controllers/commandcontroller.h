#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H


#include <QObject>
#include <QtQml/QQmlListProperty>

#include <cms-lib_global.h>
#include <framework/command.h>


namespace cms {
namespace controllers {

class CMSLIBSHARED_EXPORT CommandController : public QObject{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<cms::framework::Command>
               ui_createPatientViewContextCommands READ
               ui_createPatientViewContextCommands)
public:
    explicit CommandController(QObject* _parent = nullptr);
    ~CommandController();

    QQmlListProperty<cms::framework::Command> ui_createPatientViewContextCommands();
public slots:
    void onCreatePatientSaveExecuted();

private:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}
}

#endif // COMMANDCONTROLLER_H
