#pragma once
#include <iostream>

/**
 * @class MergeSort
 * @brief Klasa implementująca algorytm sortowania przez scalanie (MergeSort).
 */
class MergeSort {
    public:
    /**
     * @brief Konstruktor klasy MergeSort.
     * @param size Rozmiar tablicy do posortowania.
     * @param arr Wskaźnik na tablicę do posortowania.
     */
    MergeSort(int size, int* arr);

    /**
     * @brief Destruktor klasy MergeSort.
     */
    ~MergeSort();

    /**
     * @brief Funkcja scalająca dwie posortowane części tablicy.
     * @param arr Wskaźnik na tablicę do posortowania.
     * @param start Indeks początkowy pierwszej części tablicy.
     * @param srodek Indeks końcowy pierwszej części tablicy.
     * @param koniec Indeks końcowy drugiej części tablicy.
     */
    void merge(int arr[], int start, int srodek, int koniec);

    /**
     * @brief Funkcja rekurencyjnie sortująca tablicę metodą sortowania przez scalanie.
     * @param arr Wskaźnik na tablicę do posortowania.
     * @param start Indeks początkowy tablicy.
     * @param koniec Indeks końcowy tablicy.
     */
    void mergeSort(int arr[], int start, int koniec);

    /**
     * @brief Funkcja wypisująca zawartość tablicy.
     * @param arr Wskaźnik na tablicę do wypisania.
     * @param size Rozmiar tablicy.
     */
    void print(int* arr, int size);

    private:
    /**
     * @brief Prywatny konstruktor domyślny klasy MergeSort.
     * @note Konstruktor jest prywatny, aby uniemożliwić tworzenie obiektów bez parametrów.
     */
    MergeSort();

    int size; ///< Rozmiar tablicy.
    int* arr; ///< Wskaźnik na tablicę do posortowania.
    int* sArr; ///< Wskaźnik na pomocniczą tablicę używaną podczas scalania.
};