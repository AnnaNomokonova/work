#include <ctime>
#include <random>

#include "utility.hpp"


void ILoveProgramming::generate_arrange(int * const x, const int size, const int depth){
    for(int i = 0; i < size; i++) x[i] = ILoveProgramming::random_int(depth);
}

void ILoveProgramming::set_rand(){
    srand(time(0));
}

int ILoveProgramming::random_int(const int depth){
    return rand() % depth;
}
