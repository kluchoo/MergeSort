#pragma once
#include <iostream>

class MergeSort {
    public:
    MergeSort(int size, int* arr) : size(size), arr(arr) {};
    ~MergeSort();
    void merge(int arr[], int start, int srodek, int koniec);
    void mergeSort(int arr[], int start, int koniec);
    void print(int* arr, int size);
    private:
    MergeSort();

    int size;
    int* arr = new int[size];
    int* sArr = new int[size];
};