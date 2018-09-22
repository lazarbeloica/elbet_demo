
#pragma once

#include "ISortAlgorithm.h"
#include "quickSortAlgorithm.h"
#include "../../common/configuration.h"


#include <string>

namespace algorithm {

class SortAlgorithmFactory
{
private:
    static SortAlgorithmFactory *instance;

public:
    static SortAlgorithmFactory* getInstance();

    template<class T>
    ISortAlgorithm<T>* getAlgorithm(std::string name) {

       if (name == QUICKSORT_ALGORITHM) {
            return new QuickSortAlgorithm<T>();
       }

       return nullptr;
    };

};

} // namespace algorithm