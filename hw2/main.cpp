#include "print_array.hpp"
#include "randArray.hpp"
#include "insert_sort.hpp"

int main() {
    int size = 100;
    int* arr = new int(size);
    ILoveProgramming::rand_array(arr, size, 1000);
    ILoveProgramming::print_array(arr, size);
    ILoveProgramming::insert_sort(arr, size);
    ILoveProgramming::print_array(arr, size);
    delete[] arr;
}