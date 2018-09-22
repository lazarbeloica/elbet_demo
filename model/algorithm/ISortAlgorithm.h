
#pragma once

#include <vector>

namespace algorithm {

template <class T>
class ISortAlgorithm
{
public:
    virtual void sort(std::vector<T>& toSort) = 0;
};

} // namespace algorithm