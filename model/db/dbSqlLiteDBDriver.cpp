
#include "dbSqlLiteDBDriver.h"


namespace db {

bool SqlLiteDBDriver::connect(std::string pathToDb) {
    LOG_INFO("Connecting to db...");
    rc = sqlite3_open(argv[1], &db);

    if(rc) {
      LOG_ERROR("Can't open database: " + sqlite3_errmsg(db));
      sqlite3_close(db);
      return false;
    }

}

void SqlLiteDBDriver::disconnect() {
    LOG_INFO("Disconnecting from db...");
    sqlite3_close(db);
    db = nullptr;
}

std::string parseResult(const std::vector<T>& res) const

} // namespace db