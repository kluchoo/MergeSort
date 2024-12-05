#include "MergeSort.h"
#include <iostream>

using namespace std;

MergeSort::MergeSort(int size, int* arr) : size(size), arr(arr), sArr(new int[size]) {};

MergeSort::~MergeSort() {
    delete[] sArr;
}

void MergeSort::print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MergeSort::merge(int arr[], int start, int srodek, int koniec) {
    int i = start, j = srodek + 1, k = 0;
    int* pomTab = new int[koniec - start + 1];

    while (i <= srodek && j <= koniec) {
        if (arr[i] <= arr[j]) {
            pomTab[k++] = arr[i++];
        } else {
            pomTab[k++] = arr[j++];
        }
    }

    while (i <= srodek) {
        pomTab[k++] = arr[i++];
    }

    while (j <= koniec) {
        pomTab[k++] = arr[j++];
    }

    for (int i = 0; i < k; i++) {
        arr[start + i] = pomTab[i];
    }

    delete[] pomTab;
}


void MergeSort::mergeSort(int arr[], int start, int koniec) {
    if (start < koniec) {
        int srodek = (start + koniec) / 2;
        mergeSort(arr, start, srodek);
        mergeSort(arr, srodek + 1, koniec);
        merge(arr, start, srodek, koniec);
    }
}
