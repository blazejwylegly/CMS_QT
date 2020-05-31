#include "AccountDAO.h"

std::unique_ptr<AccountData> AccountDAO::get(const std::string& login){
    std::string query = "SELECT * FROM ";
    query.append(tableName).append(" WHERE login = ");
    query.append("'").append(login).append("'");

    std::unique_ptr<AccountData> ptr = nullptr;
    QSqlQuery result  = SQLManager::execute(query.c_str());

    if(result.isActive()){
        AccountData account;
        result.first();
        if(result.isValid()){
            ptr = account.deserialize(result);
        }
        SQLManager::finish(result);
    }
    return ptr;

}
