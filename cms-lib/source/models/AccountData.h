#pragma once
#include <string>
#include "data-mngmnt/SQLAdapter.h"

#include "utility/Encryptor.h"


#include <QtSql/QSqlQuery>
#include <QVariant>


class AccountData : public SQLAdapter<AccountData>
{

private:

    //data retrieved
	std::string login;
	std::string password;
    bool admin;
    std::string salt;

public:

    AccountData(){ };

    //Account creation
    AccountData(const std::string& _login, const std::string& _pswd,
                const bool& _admin)
                :login(_login), password(_pswd), admin(_admin){

        Encryptor::encode(password, salt);
    }

    //Account deserialization
    AccountData(const std::string& _login, const std::string& _pswd,
                const bool& _admin, const std::string& _salt)
                :login(_login), password(_pswd),
                 admin(_admin), salt(_salt) {};


    virtual std::string marshal() const override;
    virtual std::unique_ptr<AccountData> deserialize(QSqlQuery& row) override;
    virtual std::vector<std::unique_ptr<AccountData>> deserializeAll(QSqlQuery& result) override;

    bool authenticate(const std::string& pwd);

    std::string getLogin() const {
        return this->login;
    }

    std::string getSalt() const {
        return this->salt;
    }

    bool isAdmin() const {
        return this->admin;
    }


};

