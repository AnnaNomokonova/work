#include <cmath>
#include <iostream>
#include <limits>

#include "MySort.hpp"

void ILoveProgramming::insertionSort(int* const arr, const int size) {
    for (int i = 2; i < size; i++) {
        if (arr[i - 2] < arr[i - 1] && arr[i - 1] < arr[i]) {
            std::swap(arr[i - 1], arr[i]);
        } else if (arr[i - 2] > arr[i - 1] && arr[i - 1] > arr[i]) {
            std::swap(arr[i - 1], arr[i]);
        }
    }
}
