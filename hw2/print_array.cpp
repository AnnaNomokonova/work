#include "print_array.hpp"
#include <iostream>

void ILoveProgramming::print_array(int arr[], int size){
    for (int i = 0; i < size; ++i){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}