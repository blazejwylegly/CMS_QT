#ifndef ACCOUNTDAO_H
#define ACCOUNTDAO_H

#include <models/AccountData.h>
#include "data-mngmnt/DAO.h"

//typedef std::unique_ptr<AccountData> Account;
//typedef std::vector<Account> AccountsColl;

class AccountDAO : public DAO<AccountData>
{
public:
    AccountDAO(): DAO("login, hash, admin, salt", "accounts") {};

    std::unique_ptr<AccountData> get(const std::string& login);
};

#endif // ACCOUNTDAO_H
