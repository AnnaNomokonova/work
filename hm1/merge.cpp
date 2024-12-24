#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()

void insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void modifiedMergeSort(std::vector<int>& arr, int left, int right, int m) {
    if (right - left + 1 <= m) {
        insertionSort(arr, left, right);
        return;
    }

    int mid = left + (right - left) / 2;
    modifiedMergeSort(arr, left, mid, m);
    modifiedMergeSort(arr, mid + 1, right, m);
    merge(arr, left, mid, right);
}

int main() {
    // Устанавливаем начальное значение для генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Определяем размер массива и диапазон случайных чисел
    const int size = 100; // Например, 100 элементов
    const int minValue = 1; // Минимальное значение
    const int maxValue = 1000; // Максимальное значение

    // Генерируем случайный массив
    std::vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % (maxValue - minValue + 1) + minValue; // Генерация случайного числа в диапазоне
    }

    // Печатаем исходный массив
    std::cout << "Исходный массив: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // Выбираем значение m
    int m = 5; // Например, 5

    // Сортируем массив
    modifiedMergeSort(arr, 0, size - 1, m);

    // Печатаем отсортированный массив
    std::cout << "Отсортированный массив: ";
    for (int i : arr) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
