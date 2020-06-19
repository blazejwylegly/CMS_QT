#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>

#include <controllers/patientslistmodel.h>
#include <controllers/maincontroller.h>

#include <models/Patient.h>
#include <models/AccountData.h>

#include "administration/Organiser.h"

#include <cms-lib_global.h>

int main(int argc, char *argv[])
{

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<cms::controllers::PatientsListModel>("CMS", 1, 0, "PatientsListModel");
    //qmlRegisterType<cms::controllers::MenuBarController>("CMS", 1, 0, "menuBarController");
    //qmlRegisterType<cms::controllers::LoginViewController>("CMS", 1, 0, "loginController");

    QQmlApplicationEngine engine;


    engine.addImportPath("qrc:/");
    engine.load(QUrl(QStringLiteral("qrc:/views/main.qml")));
    cms::controllers::MainController mc(&engine);

    return app.exec();

//    accountCreationTest();
    return 0;

    //cms::controllers::MasterController masterController;


    //engine.rootContext()->setContextProperty("masterController", &masterController);



//    cms::controllers::LoginViewController lvc(&engine);
//


}
