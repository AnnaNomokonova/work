#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <algorithm> 

using namespace std;

vector<int> generateUniqueRandomNumbers(int n, int min, int max) {
    set<int> uniqueNumbers; 
    vector<int> result;

    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(min, max); 
    while (uniqueNumbers.size() < n) {
        int num = dis(gen); 
        uniqueNumbers.insert(num); 
    }

    
    for (const int& num : uniqueNumbers) {
        result.push_back(num); 
    }

    return result; 
}

void merge(vector<int>& arr, int left, int mid, int right, unsigned int S) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    int i = 0, j = 0; 

    while (i < n1 && j < n2) {
        int sum = L[i] + R[j];

        if (sum == S) {
            cout << "Пара найдена: (" << L[i] << ", " << R[j] << ")\n";
            i++;
            j++;
        } else if (sum < S) {
            i++;
        } else {
            j++; 
        }
    }

    i = 0; 
    j = 0; 
    int k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++]; 
        } else {
            arr[k++] = R[j++]; 
        }
    }

     if (i < n1) {
        std::copy(L.begin() + i, L.end(), arr.begin() + k);
    }
    if (j < n2) {
        std::copy(R.begin() + j, R.end(), arr.begin() + k);
    }
}

void mergeSort(vector<int>& arr, int left, int right, unsigned int S) {
    if (left < right) { 
        int mid = left + (right - left) / 2; 
        mergeSort(arr, left, mid, S); 
        mergeSort(arr, mid + 1, right, S); 

        merge(arr, left, mid, right, S); 
    }
}

int main() {
    int n;
    cout << "Введите количество элементов  ";
    cin >> n;

    int minValue = 1;
    int maxValue = 100; 
    if (n > (maxValue - minValue + 1)) {
        cout << "Ошибка: невозможно сгенерировать " << n << " уникальных чисел в диапазоне от " << minValue << " до " << maxValue << ".\n";
        return 1;
    }

vector<int> arr = generateUniqueRandomNumbers(n, minValue, maxValue); 
   
    cout << endl;

    unsigned int S;
    cout << "Введите сумму S: ";
    cin >> S;

    mergeSort(arr, 0, n - 1, S); 

    return 0;
}
