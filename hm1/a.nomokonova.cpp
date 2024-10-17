#include <cmath> 
#include <iostream> 

int main() 
{ 
    const int arr_size = 10;
    int a[arr_size];
    for (int i = 0; i < arr_size; i++) 
    { 
        std::cout << "введите целочисленные " << i << " элемент " << std::endl; 
        std::cin >> a[i]; 
    } 
    
    int i = 0;
    bool is_increasing = true; 
    while ((i < arr_size - 1)) 
    { 
        if (a[i] > a[i + 1]) {
            is_increasing = false; 
            break;
            }
        i++; 
    } 
    if (is_increasing == true) { 
        std::cout << "последовательность возрастающая"<< std::endl; 
    } 
    else  { 
        std::cout << "последовательность не возрастающая"<< std::endl; 
    } 
 
    return 0; 
}
