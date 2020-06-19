#ifndef PATIENTSDISPLAYCONTROLLER_H
#define PATIENTSDISPLAYCONTROLLER_H

#include <iostream>

#include <QObject>
#include <QString>
#include <QQmlApplicationEngine>

#include <cms-lib_global.h>

namespace cms {
namespace controllers {

class PatientsDisplayController : public QObject
{
    Q_OBJECT
private:
    QQmlApplicationEngine* engine {nullptr};

    QObject* rootObject {nullptr};
    QObject* searchButton {nullptr};
    QObject* searchBar {nullptr};

    void initialize();
    void setConnections();
public:
    explicit PatientsDisplayController(QQmlApplicationEngine* _engine);

signals:

public slots:
    void searchButtonClicked(QString searchText);
};

}
}



#endif // PATIENTSDISPLAYCONTROLLER_H
