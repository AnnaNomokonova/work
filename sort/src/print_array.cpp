#include "print_array.hpp"
#include <iostream>

void ILoveProgramming::print_array(int arr[], int size){
    const char format = ' ';
    std::cout << sizeof (format);
    for (int i = 0; i < size; ++i){
        std::cout << arr[i] << format;
    }
    std::cout << std::endl;
}