#include "commandcontroller.h"

#include <QList>
#include <QDebug>

using namespace cms::framework;

namespace cms{
namespace controllers{

class CommandController::Implementation{

public:
    //Controller
    CommandController* commandController {nullptr};
    //Commands
    QList<Command*> createPatientViewContextCommands;


    Implementation(CommandController* _commandController) :
        commandController(_commandController)
    {

        Command* createPatientSaveCommand = new Command(commandController,
                                                       QChar(0xf0c7),
                                                       "Save");

        QObject::connect(createPatientSaveCommand,
                         &Command::executed,
                         commandController,
                         &CommandController::onCreatePatientSaveExecuted);

        createPatientViewContextCommands.append(createPatientSaveCommand);

    }


};

CommandController::CommandController(QObject* parent) : QObject(parent){
    implementation.reset(new Implementation(this));
}

CommandController::~CommandController(){

}

QQmlListProperty<Command> CommandController::ui_createPatientViewContextCommands(){
    return QQmlListProperty<Command>(this, implementation->createPatientViewContextCommands);
}

void CommandController::onCreatePatientSaveExecuted(){
    qDebug() << "You executed the Save commands!";
}


}
}
