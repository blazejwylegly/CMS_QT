#pragma once

#include <QtSql/QSqlQuery>

#include <string>
#include <vector>
#include <memory>

template <class T>
class SQLAdapter
{
public:
	virtual std::string marshal() const = 0;
    virtual std::unique_ptr<T> deserialize(QSqlQuery& row) = 0;
    virtual std::vector<std::unique_ptr<T>> deserializeAll(QSqlQuery& result) = 0;
	
};

