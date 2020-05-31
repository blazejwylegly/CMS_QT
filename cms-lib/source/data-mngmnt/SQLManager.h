#pragma once
#include <models/Patient.h>
#include <models/Doctor.h>

#include <QtSql/QSqlDatabase>
#include <QString>

#include <memory.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <list>

typedef std::list<std::string> queryList;

class SQLManager
{
private:

    static QSqlDatabase db;

    static void establishConnection(){
        //db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setDatabaseName("clinic");
        db.setUserName("root");
        db.setPassword("root");
        db.setPort(3306);

        if(db.open()){
            std::cout<<"Connection successful"<<std::endl;
        }
        else{
            std::cout<<"Connection failed"<<std::endl;
        }

    }

public:

    static void finish(QSqlQuery& query){
        query.finish();
        db.close();
    }

    static bool executeRemoval(const char* query) {
        std::cout << "Executing query: " << query << std::endl;
        establishConnection();

        if (db.isOpen()) {
            QSqlQuery sqlQuery;
            sqlQuery.exec(query);
            if(sqlQuery.numRowsAffected() == 1){
                return true;
            }
        }
        return false;
    }

    /*
    Executes insert query, returns id of added recod ONLY in case insert succeded
    */
    static int executeInsert(const char* query) {
         std::cout << "Executing query: " << query << std::endl;

         establishConnection();

         if (db.isOpen()) {
            QSqlQuery sqlQuery;
            if (sqlQuery.exec(query)) {
                int id = sqlQuery.lastInsertId().toInt();
                sqlQuery.finish();
                return id;
            }
            sqlQuery.finish();
         }

         return -1;
     };

    static QSqlQuery execute(const char* query) {
        //std::cout << "Executing query: " << query << std::endl;

        establishConnection();
        QSqlQuery sqlQuery;
        sqlQuery.exec(query);
        return sqlQuery;

    }

};


