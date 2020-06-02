#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QQmlContext>

#include "controllers/mastercontroller.h"
#include <controllers/navigation-controller.h>
#include <controllers/commandcontroller.h>
#include <controllers/loginviewcontroller.h>

#include <framework/command.h>


int main(int argc, char *argv[])
{

    /*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    THE PARENT OF ANY GIVEN QML COMPONENT IS THE QML COMPONENT THAT CONTAINS IT
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    */
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    //Registering type with qml engine
    qmlRegisterType<cms::controllers::MasterController>("CMS", 1, 0, "MasterController");
    qmlRegisterType<cms::controllers::NavigationController>("CMS", 1, 0, "NavigationController");
    qmlRegisterType<cms::framework::Command>("CMS", 1, 0, "Command");
    qmlRegisterType<cms::controllers::CommandController>("CMS", 1, 0, "CommandController");


    cms::controllers::MasterController masterController;

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");

    engine.rootContext()->setContextProperty("masterController", &masterController);

    engine.load(QUrl(QStringLiteral("qrc:/views/MasterView.qml")));

    cms::controllers::LoginViewController lvc(&engine);
    engine.rootContext()->setContextProperty("loginController", &lvc);

//    QObject* loginView = engine.rootObjects().first()->findChild<QObject*>("loginView");

//    loginView->setProperty("ui_loginController", QVariant::fromValue(masterController.loginController()));

//    const QUrl url(QStringLiteral("qrc:/views/MasterView.qml"));
//    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
//                     &app, [url](QObject *obj, const QUrl &objUrl) {
//        if (!obj && url == objUrl)
//            QCoreApplication::exit(-1);
//    }, Qt::QueuedConnection);
//    engine.load(url);

    return app.exec();
}
