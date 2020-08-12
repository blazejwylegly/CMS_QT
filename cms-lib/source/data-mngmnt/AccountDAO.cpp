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
    std::cout << ptr.get() << std::endl;
    return ptr;

}

int AccountDAO::add(const AccountData& obj){

    std::string query = "INSERT INTO";
    query.append(tableName).append("(");
    query.append(columns).append(")\n").append("VALUES (");
    query.append(obj.marshal()).append(")");
    return SQLManager::executeInsert(query.c_str());

}

bool AccountDAO::remove(const int& id){
    std::string query = "DELETE FROM ";
    query.append(tableName).append(" WHERE id = ");
    query.append(std::to_string(id));
    return SQLManager::executeRemoval(query.c_str());
}
