
#include "dbDriverFactroy.h"

namespace db {

DBDriverFactory *DBDriverFactory::instance = nullptr;

DBDriverFactory* DBDriverFactory::getInstance() {
    if (!instance) {
        instance = new DBDriverFactory();
    }

    return instance;
};

} // namespace db
