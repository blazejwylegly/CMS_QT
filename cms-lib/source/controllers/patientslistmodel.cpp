#include "patientslistmodel.h"

namespace cms {
namespace controllers {

PatientsListModel::PatientsListModel(QObject* parent) : QAbstractListModel(parent){
    clear();
    update();
}

PatientsListModel::~PatientsListModel()
{

}

void PatientsListModel::deletePatient(){

}

void PatientsListModel::editPatient(){

}

void PatientsListModel::update(){
    clear();

    emit beginResetModel();
    std::vector<std::unique_ptr<Patient>> patients = Clinic::getAllPatients();

    for(auto it = patients.begin(); it != patients.end(); it++){
        const auto ptr = (*it).get();

        QString name = QString::fromStdString(ptr->getFullName()),
                pesel = QString::fromStdString(ptr->getPesel());
        QVariant docId = QVariant(ptr->getDocId());

        addItem(name, pesel, docId);
    }

    emit endResetModel();
}

void PatientsListModel::clear(){
    emit beginResetModel();
    mPatients.clear();
    emit endResetModel();
}

void PatientsListModel::doSearch(QString searchText){

    //If search text isn't provided, load deafult model (all patients)
    if(searchText.isNull() || searchText.isEmpty()){
       update(); emit nothingFound(); return;
    }

    std::string text = searchText.toLower().toStdString();

    //Regex to check whether string is a valid pesel number, 11 digits
    std::regex numberRegex("\\d+");
    //Regex used to find specified characters in patients full name
    std::regex reg(text);

    QList<PatientItem> itemsFound;


    if(std::regex_match(text, numberRegex)){
        //Filtering list with pesel numbers
        for(const PatientItem& item : mPatients){

            std::string pesel = item.pesel.toStdString();

            if(std::regex_search(pesel, reg)){
                itemsFound.append({item.name, item.pesel, item.docId});
            }
        }
    }else {
        //Filtering list with patients surname
        for(const PatientItem& item : mPatients){

            std::string name = item.name.toLower().toStdString();

            if(std::regex_search(name, reg)){
                itemsFound.append({item.name, item.pesel, item.docId});
            }
        }
    }

    //None items were found - load default model
    if(itemsFound.isEmpty()){
        update(); emit nothingFound(); return;
    }

    //Load new model if list not empty
    clear();
    emit beginResetModel();
    mPatients = itemsFound;
    emit endResetModel();
}

int PatientsListModel::rowCount(const QModelIndex& parent) const {
    Q_UNUSED(parent);
    return mPatients.count();
}

QVariant PatientsListModel::data(const QModelIndex& index, int role) const {

    int row = index.row();
    if(row < 0 || row > mPatients.count()) return QVariant();

    const PatientItem& patient = mPatients.at(row);

    switch(role){
    case NameRole:
        //return first name - model.firstName
        return patient.name;
    case PeselRole:
        //return pesel number - model.pesel
        return patient.pesel;
    case DocIdRole:
        //return id of doctor in charge - model.docId
        return patient.docId;
    default:
        return QVariant();

    }

}

bool PatientsListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(mPatients.empty()) return false;

    PatientItem patient = mPatients.at(index.row());

    if(data(index, role) != value){
        //FIXME: IMPLEMENT ME!
        emit dataChanged(index, index, QVector<int>() << role); return true;
    }
    return false;
}

Qt::ItemFlags PatientsListModel::flags(const QModelIndex &index) const
{
    if(!index.isValid()) return Qt::NoItemFlags;
    return Qt::ItemIsEditable;
    //FIXME: IMPLEMENT ME!
}

QHash<int, QByteArray> PatientsListModel::roleNames() const{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[PeselRole] = "pesel";
    roles[DocIdRole] = "docId";

    return roles;
}

bool PatientsListModel::addItem(const QString& name, const QString& pesel,
                                const QVariant& docId){
    emit beginInsert();

    mPatients.append({name, pesel, docId});

    emit endInsert();
    return true;

}

bool PatientsListModel::addItem(const PatientItem& item){
    emit beginInsert();
    mPatients.append(item);
    emit endInsert();
}

}
}

