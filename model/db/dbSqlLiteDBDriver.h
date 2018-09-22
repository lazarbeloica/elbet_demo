#pragma once

#include "IDBDriver.h"

namespace db {

class SqlLiteDBDriver: public IDBDriver
{
public:
    virtual bool connect() override;
    virtual void disconnect() override;
    virtual bool storeResult(const int res) const override;
};

} // namespace db