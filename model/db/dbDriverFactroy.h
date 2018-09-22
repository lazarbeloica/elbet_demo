
#pragma once

#include "IDBDriver.h"

#include <string>

namespace db {

class DBDriverFactory
{
private:
    static DBDriverFactory *instance;

public:
    static DBDriverFactory* getInstance();

    IDBDriver* getDB(std::string name);

};

}
