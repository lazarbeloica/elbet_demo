
#pragma once

#include "IDBDriver.h"
#include "dbSqlLiteDBDriver.h"
#include "../../common/configuration.h"

#include <string>

namespace db {

class DBDriverFactory
{
private:
    static DBDriverFactory *instance;

public:
    static DBDriverFactory* getInstance();

    template<class T>
    IDBDriver<T>* getDB(std::string name) {

        if (name == SQLITE_DB_DRIVER) {
            return new SqlLiteDBDriver<T>();
        }

        return nullptr;
    };

};

}
