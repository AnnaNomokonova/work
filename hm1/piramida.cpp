#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 3 * i + 1; 
    int middle = 3 * i + 2; 
    int right = 3 * i + 3; 

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }
 
    if (middle < n && arr[middle] > arr[largest]) {
        largest = middle;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]); 

        heapify(arr, n, largest);
    }
}

void ternaryHeapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 3 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); 
        heapify(arr, i, 0);
    }
}

vector<int> generateRandomArray(int n) {
    vector<int> arr(n);
    random_device rd; 
    mt19937 gen(rd());
    uniform_int_distribution<> dis(INT32_MIN, INT32_MAX); 

    for (int i = 0; i < n; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

void compareSorts(int n) {
    vector<int> arr = generateRandomArray(n);

    vector<int> arr_copy = arr;

    auto start = chrono::high_resolution_clock::now();
    ternaryHeapSort(arr);
    auto end = chrono::high_resolution_clock::now();
    auto ternary_time = chrono::duration_cast<chrono::microseconds>(end - start).count();

    start = chrono::high_resolution_clock::now();
    sort(arr_copy.begin(), arr_copy.end());
    end = chrono::high_resolution_clock::now();
    auto std_sort_time = chrono::duration_cast<chrono::microseconds>(end - start).count();

    cout << "Количество элементов: " << n << "\n";
    cout << "Время тернарной сортировки: " << ternary_time << " микросекунд\n";
    cout << "Время std::sort: " << std_sort_time << " микросекунд\n";
    cout << "---------------------------------------\n";
}

int main() {
    for (int n = 1000; n <= 100000000; n *= 10) {
        compareSorts(n);
    }
    return 0;
}
