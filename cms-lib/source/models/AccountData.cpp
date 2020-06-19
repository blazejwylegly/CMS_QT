#include "AccountData.h"


std::string AccountData::marshal() const{
    std::string query;
    query.append("'").append(login).append("',");
    query.append("'").append(password).append("',");
    if (admin) {
        query.append("1,");
    }
    else {
        query.append("0,");
    }
    query.append("'").append(salt).append("'");
    return query;
}

std::unique_ptr<AccountData> AccountData::deserialize(QSqlQuery& row){
    if(row.isValid()){
        std::string login, password, salt;
        bool admin;
        login = row.value(1).toString().toStdString();
        password = row.value(2).toString().toStdString();
        admin = row.value(3).toBool();
        salt = row.value(4).toString().toStdString();
        return std::make_unique<AccountData>(login, password, admin, salt);
    }
    return nullptr;
}

std::vector<std::unique_ptr<AccountData>> AccountData::deserializeAll(QSqlQuery& result){
    std::vector<std::unique_ptr<AccountData>> accounts;
    if(result.isActive()){
        while(result.next()){
            accounts.push_back(deserialize(result));
        }
    }
    return accounts;
}

bool AccountData::authenticate(const std::string& pwd){
    return password == Encryptor::constEncode(pwd, salt);
}



