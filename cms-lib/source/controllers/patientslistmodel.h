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


public:
    explicit PatientsListModel(QObject* parent = nullptr);
    ~PatientsListModel();

    enum RoleNames{
        NameRole = Qt::UserRole,
        PeselRole,
        DocIdRole
    };

    Q_INVOKABLE void deletePatient();
    Q_INVOKABLE void editPatient();
    Q_INVOKABLE void update();
    Q_INVOKABLE void clear();
    Q_INVOKABLE void doSearch(QString searchText);

    //QAbstractListModel inherited methods
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex& index, const QVariant& value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
    virtual QHash<int, QByteArray> roleNames() const override;

    bool addItem(const QString&, const QString&, const QVariant&);



signals:
    void beginInsert();
    void endInsert();
    void beginRemoval();
    void endRemoval();

    void nothingFound();


private:

    struct PatientItem{
        QString name,
                pesel;
        QVariant docId;
    };

    QList<PatientItem> mPatients {};
    int mItemCount {0};


public:
    bool addItem(const PatientItem& item);
};

}
}


#endif // PATIENTSLISTMODEL_H
