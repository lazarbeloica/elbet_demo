
#include "../quickSortAlgorithm.h"

#include <gtest/gtest.h>

#include <vector>

namespace {

TEST(sort, Positive) {
    std::vector<int> input = {5, 1, 2, 3, 11};
    std::vector<int> res   = {1, 2, 3, 5, 11};

    algorithm::QuickSortAlgorithm<int> *alg = new algorithm::QuickSortAlgorithm<int>();
    alg->sort(input);
    EXPECT_EQ(input, res);
}

TEST(sort, Negative) {
    std::vector<int> input = {-5, -1, -2, -3, -11};
    std::vector<int> res   = {-11, -5, -3, -2, -1};

    algorithm::QuickSortAlgorithm<int> *alg = new algorithm::QuickSortAlgorithm<int>();
    alg->sort(input);
    EXPECT_EQ(input, res);
}

TEST(sort, Normal) {
    std::vector<int> input = {5, -1, 2, -3, -11, -1100, 15552, 0, 3, -18, 0};
    std::vector<int> res =   {-1100, -18, -11, -3, -1, 0, 0, 2, 3, 5, 15552};

    algorithm::QuickSortAlgorithm<int> *alg = new algorithm::QuickSortAlgorithm<int>();
    alg->sort(input);
    EXPECT_EQ(input, res);
}


TEST(sort, Empty) {
    std::vector<int> input = {};
    std::vector<int> res = {};

    algorithm::QuickSortAlgorithm<int> *alg = new algorithm::QuickSortAlgorithm<int>();
    alg->sort(input);
    EXPECT_EQ(input, res);
}

TEST(sort, One) {
    std::vector<int> input = {5};
    std::vector<int> res   = {5};

    algorithm::QuickSortAlgorithm<int> *alg = new algorithm::QuickSortAlgorithm<int>();
    alg->sort(input);
    EXPECT_EQ(input, res);
}

}