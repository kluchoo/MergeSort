#include <iostream>
#include "MergeSort.h"

using namespace std;

int main() {
  int iloscLiczb = 0;
  cout << "Podaj ilosc liczb do posortowania: ";
  cin >> iloscLiczb;
  int* tablica = new int[iloscLiczb];
  cout << "Podaj liczby do posortowania: ";
  for (int i = 0; i < iloscLiczb; i++) {
    cin >> tablica[i];
  }
  MergeSort tab(iloscLiczb, tablica);
  tab.mergeSort(tablica, 0, iloscLiczb - 1);
  cout << "Posortowane liczby wpisywane przez uzytkownika: ";
  tab.print(tablica, iloscLiczb);

  int tablica2[100];
  for (int i = 0; i < 100; i++) {
    tablica2[i] = rand() % 100 - 50;
  }
  MergeSort tab2(100, tablica2);
  tab2.mergeSort(tablica2, 0, 99);
  cout << "Posortowane liczby losowe: ";
  tab2.print(tablica2, 100);

  return 0;
}
