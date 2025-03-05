// tests/sorting_test.cpp
#include <gtest/gtest.h>
#include "insert_sort.hpp"
#include "randArray.hpp"
#include "print_array.hpp"

TEST(SortingTest, HandlesUnsortedArray) {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 5, 5, 6, 9})); // Проверяем результат
}

TEST(SortingTest, HandlesAlreadySortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{1, 2, 3, 4, 5})); // Проверяем результат
}

TEST(SortingTest, HandlesEmptyArray) {
    std::vector<int> arr = {};
    sort(arr);
    EXPECT_EQ(arr, (std::vector<int>{})); // Проверяем результат
}

