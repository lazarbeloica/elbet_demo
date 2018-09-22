#pragma once

#include "IDBDriver.h"
#include "../../common/logger.h"
#include "../../common/configuration.h"

#include <iostream>
#include <string>
#include <sstream>

#include <sqlite3.h>

namespace db {


template<class T>
class SqlLiteDBDriver: public IDBDriver<T>
{
private:
    sqlite3 *db = nullptr;

protected:
    virtual std::string parseResult(const std::vector<T>& res) const {

        std::ostringstream parsedResult;

        for(int i = 0; i < res.size() - 1; parsedResult << res[i++] << RESULT_SCORE_DELIMITER);
        parsedResult << res[res.size() - 1];
        return parsedResult.str();
    }

public:
    virtual bool connect(const std::string pathToDb) override  {
        int rc;
        LOG_INFO("Connecting to db...");
        rc = sqlite3_open(pathToDb.c_str(), &db);

        if(rc) {
          LOG_ERROR("Can't open database: " << sqlite3_errmsg(db));
          sqlite3_close(db);
          return false;
        }

        return true;
    }

    virtual void disconnect() override {
        LOG_INFO("Disconnecting from db...");
        sqlite3_close(db);
        db = nullptr;
    }

    virtual bool storeResult(const std::vector<T>& res) const {
        if(!db) {
            LOG_ERROR("No connection to db!");
            return false;
        }

        std::ostringstream query;
        query << "INSERT INTO game_record (sortirani_niz) values ('"
              << parseResult(res)
              << "');";

        int rc;
        char *zErrMsg = 0;
        rc = sqlite3_exec(db, query.str().c_str(), nullptr, 0, &zErrMsg);
        if( rc!=SQLITE_OK ){
          LOG_ERROR("SQL error: " << zErrMsg);
          sqlite3_free(zErrMsg);
        }
    };
};

} // namespace db