#pragma once
#include <iostream>

/**
 * @class MergeSort
 * @brief Klasa implementujaca algorytm sortowania przez scalanie (MergeSort).
 */
class MergeSort {
    public:
    /**
     * @brief Konstruktor klasy MergeSort.
     * @param size Rozmiar tablicy do posortowania.
     * @param arr Wskaznik na tablice do posortowania.
     */
    MergeSort(int size, int* arr);

    /**
     * @brief Destruktor klasy MergeSort.
     */
    ~MergeSort();

    /**
     * @brief Funkcja scalajaca dwie posortowane czesci tablicy.
     * @param arr Wskaznik na tablice do posortowania.
     * @param start Indeks poczatkowy pierwszej czesci tablicy.
     * @param srodek Indeks koncowy pierwszej czesci tablicy.
     * @param koniec Indeks koncowy drugiej czesci tablicy.
     */
    void merge(int arr[], int start, int srodek, int koniec);

    /**
     * @brief Funkcja rekurencyjnie sortujaca tablice metoda sortowania przez scalanie.
     * @param arr Wskaznik na tablice do posortowania.
     * @param start Indeks poczatkowy tablicy.
     * @param koniec Indeks koncowy tablicy.
     */
    void mergeSort(int arr[], int start, int koniec);

    /**
     * @brief Funkcja wypisujaca zawartosc tablicy.
     * @param arr Wskaznik na tablice do wypisania.
     * @param size Rozmiar tablicy.
     */
    void print(int* arr, int size);

    private:
    /**
     * @brief Prywatny konstruktor domyslny klasy MergeSort.
     * @note Konstruktor jest prywatny, aby uniemozliwic tworzenie obiektow bez parametrow.
     */
    MergeSort();

    int size; ///< Rozmiar tablicy.
    int* arr; ///< Wskaznik na tablice do posortowania.
    int* sArr; ///< Wskaznik na pomocnicza tablice uzywana podczas scalania.
};