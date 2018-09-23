#pragma once

#include <vector>
#include <string>

namespace db {

template<class T>
class IDBDriver
{
public:
    virtual bool connect(std::string pathToDb) = 0;
    virtual void disconnect() = 0;

    virtual bool storeResult(const std::vector<T>& res) const = 0;
};

} // namespace db