#pragma once
#include "SQLAdapter.h"
#include "SQLManager.h"
#include <memory>
#include <vector>



template <class T>
class DAO{
protected:
	std::string tableName;
	std::string columns;

public:

	DAO(const std::string& _columns, const std::string& _tableName) :
		columns(_columns), tableName(_tableName) {};

    virtual std::unique_ptr<T> get(const int& arg) {
        std::string query = "SELECT * FROM ";
        query.append(tableName).append(" WHERE id = ");
        query.append(std::to_string(arg));

        QSqlQuery result  = SQLManager::execute(query.c_str());
        std::unique_ptr<T> ptr = nullptr;
        if (result.isActive()) {
            T person;
            result.first();
            if(result.isValid()){
                ptr = person.deserialize(result);
            }
            SQLManager::finish(result);
        }
        return ptr;
    };

    virtual std::vector<std::unique_ptr<T>> getAll() {

        std::string query = "SELECT * FROM ";
        query.append(tableName);

        T t;
        QSqlQuery result = SQLManager::execute(query.c_str());

        auto vector = t.deserializeAll(result);
        SQLManager::finish(result);
        return vector;
    };

    virtual int add(const SQLAdapter<T>& obj) {
        std::string query = "INSERT INTO ";
        query.append(tableName).append("(");
        query.append(columns).append(")\n").append("VALUES (");
        query.append(obj.marshal()).append(")");
        return SQLManager::executeInsert(query.c_str());

    };

//	virtual bool update(const SQLAdapter<T>& ob1, const SQLAdapter<T>& obj2) = 0;

    virtual bool remove(int id) {
        std::string query = "DELETE FROM ";
        query.append(tableName).append(" WHERE id = ");
        query.append(std::to_string(id));
        return SQLManager::executeRemoval(query.c_str());
    };

//	virtual bool removeAll() {
//		std::string query = "DELETE FROM ";
//		return SQLManager::executeRemoval(query.append(tableName).c_str());
//	}
};


