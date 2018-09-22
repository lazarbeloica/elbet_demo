
#include "dbDriverFactroy.h"

namespace db {

DBDriverFactory *DBDriverFactory::instance = nullptr;

DBDriverFactory* DBDriverFactory::getInstance() {
    if (!instance) {
        instance = new DBDriverFactory();
    }

    return instance;
}

IDBDriver* DBDriverFactory::getDB(std::string name) {

    if (name == "sqllite") {
        return nullptr;
    }

    return nullptr;
};

} // namespace db
