#include <iostream>
#include "MySort.hpp"

int main() {
    std::vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    int n = arr.size();
    int m = 4;

    mergeSortModified(arr, 0, n - 1, m);

    std::cout << "Отсортированный массив: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
