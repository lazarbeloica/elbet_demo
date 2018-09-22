
#include "sortAlgorithmFactory.h"

namespace algorithm {

SortAlgorithmFactory *SortAlgorithmFactory::instance = nullptr;

SortAlgorithmFactory* SortAlgorithmFactory::getInstance() {
    if(!instance) {
        instance = new SortAlgorithmFactory();
    }
    return instance;
}

} // namespace algorithm