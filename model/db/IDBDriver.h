#pragma once

namespace db {

class IDBDriver
{
public:
    virtual bool connect() = 0;
    virtual void disconnect() = 0;
    virtual bool storeResult(const int res) const = 0;
};

} // namespace db