
#pragma once

#include "ISortAlgorithm.h"
#include <iostream>

namespace algorithm {

template <class T>
class QuickSortAlgorithm: public ISortAlgorithm<T>
{
private:
    int pivot(std::vector<T>& vector, int first, int last)
    {
        int  p = first;
        T pivotElement = vector[first];

        for(int i = first + 1 ; i <= last ; i++) {
            if(vector[i] <= pivotElement) {
                p++;
                std::swap<T>(vector[i], vector[p]);
            }
        }

        std::swap<T>(vector[p], vector[first]);

        return p;
    };

    void quickSort(std::vector<T>& vector, int first, int last) {

        if(first < last) {
            int pivotElement = pivot(vector, first, last);
            std::cout<< pivotElement << std::endl;
            quickSort(vector, first, pivotElement-1);
            quickSort(vector, pivotElement+1, last);
        }
    };

public:
    virtual void sort(std::vector<T>& toSort) override {
        quickSort(toSort, 0, toSort.size() - 1);
    };
};

} // namespace algorithm