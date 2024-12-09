#include "io.hpp"

#include <iostream>

void ILoveProgramming::print(const char* const comment, const int* const x,  const int length){
    std::cout << comment;
    for(int i = 0; i < length; i++) std::cout << x[i] << ' ';
    std::cout << std::endl;
}
