#include "io.hpp"
#include "MySort.hpp"
#include "utility.hpp"

#include <conio.h>

int main() {
    ILoveProgramming::set_rand();

    int n = ILoveProgramming::random_int(40);
    int* arr = new int(n);
    ILoveProgramming::generate_arrange(arr, n, 100);


    ILoveProgramming::print("Исходный массив: ", arr, n);

    ILoveProgramming::insertionSort(arr, n);

    ILoveProgramming::print("Отсортированный массив: ", arr, n);

    _getch();
    delete [] arr;

    return 0;
}
