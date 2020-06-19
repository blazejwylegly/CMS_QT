#ifndef PATIENTSLISTMODEL_H
#define PATIENTSLISTMODEL_H

#include <regex>
#include <iostream>
#include <iterator>
#include <vector>

#include <QObject>
#include <QAbstractListModel>
#include <QString>

#include <models/Patient.h>

#include <cms-lib_global.h>

#include <administration/Clinic.h>

namespace cms {
namespace controllers {

using cms::models::Patient;
using cms::administration::Clinic;

class CMSLIBSHARED_EXPORT PatientsListModel : public QAbstractListModel
{
    Q_OBJECT

private:
    struct PatientItem{
        QString fullName,
                pesel,
                firstName,
                secondName,
                surname;
        QVariant docId;
    };
public:
    explicit PatientsListModel(QObject* parent = nullptr);
    ~PatientsListModel();

    enum RoleNames{
        NameRole = Qt::UserRole,
        PeselRole,
        DocIdRole,
        FirstNameRole,
        SecondNameRole,
        SurnameRole
    };

    Q_INVOKABLE void deletePatient(const int &itemIndex);
    Q_INVOKABLE void editPatient();
    Q_INVOKABLE void update();
    Q_INVOKABLE void clear();
    Q_INVOKABLE void doSearch(QString searchText);
    Q_INVOKABLE PatientItem getItem(int itemIndex);

    //QAbstractListModel inherited methods
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    bool addItem(const QString& fullName, const QString& pesel,
                 const QString& firstName, const QString& secondName,
                 const QString& surname, const QVariant& docId);



signals:
    void beginInsert();
    void endInsert();
    void beginRemoval();
    void endRemoval();

    void nothingFound();


private:


    QList<PatientItem> mPatients {};
    int mItemCount {0};


public:
    bool addItem(const PatientItem& item);
};

}
}


#endif // PATIENTSLISTMODEL_H
