#include "randArray.hpp"
#include <random>
#include <iostream>

void ILoveProgramming::rand_array(int* arr, int size, double max) {
    std::mt19937 mt(time(nullptr));
    for (int i = 0; i < size; ++i) {
        arr[i] = (mt() % (int) max);
    }
}