#include "insert_sort.hpp"

void ILoveProgramming::insert_sort(int A[], int size){
    for (int i = 0; i < size; ++i){
        int j = i;
        int x = A[i];
        while (j > 0 && A[j - 1] > x){
            A[j] = A[j - 1];
            --j;

        }
        A[j] = x;
    }
}