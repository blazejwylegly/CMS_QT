#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H

#include <models/AccountData.h>
#include "data-mngmnt/DAO.h"


class AccountDAO
{
private:
    std::string columns;
    std::string tableName;

public:
    AccountDAO(): columns("login, hash, admin, salt"), tableName("accounts") {};

    std::unique_ptr<AccountData> get(const std::string& login);
    int add(const AccountData&);
    bool remove(const int& id);
   // bool update(const int& id, const AccountData&);
};

#endif // ACCOUNTDAO_H
