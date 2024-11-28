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
  tab.print(tablica, iloscLiczb);


  return 0;
}
