#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>

#include "controllers/mastercontroller.h"
#include <controllers/navigation-controller.h>
#include <controllers/commandcontroller.h>
#include <controllers/loginviewcontroller.h>

#include <controllers/maincontroller.h>

#include <framework/command.h>


int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);


//    qmlRegisterType<cms::controllers::MasterController>("CMS", 1, 0, "MasterController");
//    qmlRegisterType<cms::controllers::NavigationController>("CMS", 1, 0, "NavigationController");
//    qmlRegisterType<cms::framework::Command>("CMS", 1, 0, "Command");
//    qmlRegisterType<cms::controllers::CommandController>("CMS", 1, 0, "CommandController");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    engine.load(QUrl(QStringLiteral("qrc:/views/main.qml")));
    cms::controllers::MainController mc(&engine);


    return app.exec();



    //cms::controllers::MasterController masterController;


    //engine.rootContext()->setContextProperty("masterController", &masterController);



//    cms::controllers::LoginViewController lvc(&engine);
//


}
