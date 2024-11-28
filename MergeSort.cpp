#include "MergeSort.h"
#include <iostream>

using namespace std;

MergeSort::~MergeSort() {
    delete[] arr;
}

void MergeSort::print(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void MergeSort::merge(int arr[], int start, int srodek, int koniec) {
    int* pomTab = new int[koniec - start];
    int i = start, j = srodek + 1, k = 0;

    while (i <= srodek && j <= koniec) {
        if (arr[i] < arr[j]) {
            pomTab[k] = arr[i];
            i++;
        } else {
            pomTab[k] = arr[j];
            j++;
        }
        k++;

        while (i <= srodek) {
            pomTab[k] = arr[i];
            i++;
            k++;
        }
        while (j <= koniec) {
            pomTab[k] = arr[j];
            j++;
            k++;
        }

        for (int i = 0; i < k; i++) {
            arr[start + i] = pomTab[i];
        }

    }
}

void MergeSort::mergeSort(int arr[], int start, int koniec) {
    if (start < koniec) {
        int srodek = (start + koniec) / 2;
        mergeSort(arr, start, srodek);
        mergeSort(arr, srodek + 1, koniec);
        merge(arr, start, srodek, koniec);
    }

}