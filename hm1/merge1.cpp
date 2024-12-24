#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <limits>

using namespace std;

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void modifiedMergeSort(vector<int>& arr, int m) {
    int n = arr.size();

    if (n <= 1) {
        return;
    }
  
    if (n <= m) {
        insertionSort(arr);
        return;
    }

    for (int i = 0; i < n; i += m) {
        vector<int> subArray = vector<int>(arr.begin() + i, arr.begin() + min(i + m, n));
        insertionSort(subArray);
        for(size_t j = 0; j < subArray.size(); ++j)
            arr[i + j] = subArray[j];
    }

    for (int step = m; step < n; step *= 2) {
        for (int i = 0; i < n - step; i += 2 * step) {
            int mid = min(i + step - 1, n - 1);
            int right = min(i + 2 * step - 1, n - 1);
            merge(arr, i, mid, right);
        }
    }
}

int findOptimalM(vector<int>& arr) {
    int n = arr.size();
    if (n <= 0) return 0; // Добавлено условие для пустого массива
    if (n == 1) return 1;

    double minDuration = numeric_limits<double>::max();
    int optimalM = 1;

    for(int m = 1; m <= min(n, (int)sqrt(n) * 5); m++) {
        vector<int> tempArr = arr;
        auto start = chrono::high_resolution_clock::now();
        modifiedMergeSort(tempArr, m);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end());
        bool equal = tempArr == sortedArr;
        if (!equal) {
            cout << "Fail!" << endl;
        }

        if (duration.count() < minDuration) {
            minDuration = duration.count();
            optimalM = m;
        }
    }

    return optimalM;
}

int main() {
    std::random_device rd; 
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 99);

    for(int n = 1e3; n < 1e7; n *= 10) {
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = dis(gen); 
        }

        int optimalM = findOptimalM(arr);
        cout << "Наилучшее значение m: " << optimalM << endl;

        auto start = chrono::high_resolution_clock::now();
        modifiedMergeSort(arr, optimalM);
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> duration = end - start;

        cout << "Время выполнения: " << duration.count() << " секунд" << endl;

        if (n <= 100) {
            cout << "Отсортированный массив: ";
            for (int x : arr) {
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
