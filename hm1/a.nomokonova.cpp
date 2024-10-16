#include <cmath> 
#include <iostream> 

int main() 
{ 
    int  i = 0; int b = 1; 
    double a[10]; 
    for (i = 0; i < 10; i++) 
    { 
        std::cout << "введите " << i << " элемент " << std::endl; 
        std::cin >> a[i]; 
    } 
    i = 0;
    while ((i < 9)) 
    { 
        if (a[i] > a[i + 1]) {
            b = 0; 
            break;
            }
        i++; 
    } 
    if (b == 1) { 
        std::cout << "последовательность возрастающая"<< std::endl; 
    } 
    else  { 
        std::cout << "последовательность не возрастающая"<< std::endl; 
    } 
 
    return 0; 
}
