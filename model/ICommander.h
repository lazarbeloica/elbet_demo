#pragma once

namespace model {

class ICommander
{
public:
    virtual void Reset() = 0;
    virtual void Sort() = 0;
};

} // namesoace model