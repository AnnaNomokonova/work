#include <gtest/gtest.h>
#include <vector>
#include "insert_sort.hpp" // Убедитесь, что путь правильный

TEST(SortingTest, HandlesUnsortedArray) {
    std::vector<int> arr = {5, 3, 8, 1, 2};
    ILoveProgramming::insert_sort(arr.data(), arr.size());
    // Проверка, чтобы убедиться, что массив отсортирован
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 5, 8}));
}

TEST(SortingTest, HandlesAlreadySortedArray) {
    std::vector<int> arr = {1, 2, 3, 4, 5};
    ILoveProgramming::insert_sort(arr.data(), arr.size());
    // Проверка
    EXPECT_EQ(arr, std::vector<int>({1, 2, 3, 4, 5}));
}

TEST(SortingTest, HandlesEmptyArray) {
    std::vector<int> arr;
    ILoveProgramming::insert_sort(arr.data(), arr.size());
    // Проверка
    EXPECT_TRUE(arr.empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


