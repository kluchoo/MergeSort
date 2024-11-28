#pragma once
#include <iostream>

class MergeSort {
    public:
    MergeSort(int size, int* arr) : size(size), arr(arr) {};
    ~MergeSort();
    void sort(int* arr, int size);
    void print(int* arr, int size);
    private:
    MergeSort();

    int size;
    int* arr = new int[size];
};