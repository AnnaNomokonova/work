#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 
#include <algorithm>

using namespace std;

int perebor_count(const vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
            }
        }
    } 
    return count;
}

int merge_n_count(vector<int>& arr, int left, int mid, int right) {
    int count = 0;

    vector<int> left_part(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> right_part(arr.begin() + mid + 1, arr.begin() + right + 1);

    int i = 0, j = 0, k = left;

    while (i < left_part.size() && j < right_part.size()) { 
        if (left_part[i] <= right_part[j]) {
            arr[k++] = left_part[i++];
        } else {
            arr[k++] = right_part[j++];
            count += left_part.size() - i;
        }
    }
    if (i < left_part.size()) {
        std::copy(left_part.begin() + i, left_part.end(), arr.begin() + k);
    }
    if (j < right_part.size()) {
        std::copy(right_part.begin() + j, right_part.end(), arr.begin() + k);
    }

    return count;
}

int merge_sort_n_count(vector<int>& arr, int left, int right) {
    int count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        count += merge_sort_n_count(arr, left, mid); 

        count += merge_sort_n_count(arr, mid + 1, right); 

        count += merge_n_count(arr, left, mid, right); 

    }
    return count;
}


int main() {
    int n;
    cout << "Введите размер массива: ";
    cin >> n;
    vector<int> arr(n);

    srand(time(0));

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    vector<int> arr_copy = arr;
    int result1 = merge_sort_n_count(arr, 0, n - 1); 
    int result2 = perebor_count(arr_copy);

   cout << "Количество интересных пар: " << endl;
    cout << "Слияние: " << result1 << endl;
    cout << "Перебор: " << result2 << endl;
    if (result1 == result2) {
        cout << "одинаковая сумма";
    }
    else {
        cout << "разная сумма:(";
    }

    return 0;
}
