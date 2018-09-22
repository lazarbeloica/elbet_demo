
#pragma once

#include "ISortAlgorithm.h"

namespace algorithm {

template <class T>
class QuickSortAlgorithm: public ISortAlgorithm<T>
{
public:
    virtual void sort(std::vector<T>& toSort) override {

    };
};

} // namespace algorithm