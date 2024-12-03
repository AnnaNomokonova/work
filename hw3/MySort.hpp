#ifndef MYSORT_HPP
#define MYSORT_HPP

#include <vector>

void insertionSort(std::vector<int>& arr, int left, int right);
void merge(std::vector<int>& arr, int left, int mid, int right);
void mergeSortModified(std::vector<int>& arr, int left, int right, int m);

#endif // MYSORT_HPP
