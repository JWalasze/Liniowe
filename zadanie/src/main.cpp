#include <iostream>
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "Wektor.hh"



using namespace std;

/*
 * Tu definiujemy pozostale funkcje.
 * Lepiej jednak stworzyc dodatkowy modul
 * i tam je umiescic. Ten przyklad pokazuje
 * jedynie absolutne minimum.
 */


int main()
{
  //UkladRownanLiniowych   UklRown;   // To tylko przykladowe definicje zmiennej

  Wektor W1(2,-4,1);
  Wektor W2(-1,2,3);
  Wektor W3(1,3,2);

  MacierzKw Mac1(W1, W2, W3);
  cout << Mac1 << endl;

  cout << Mac1.wyznacznik() << endl;

  Mac1.rzad();


cin >> Mac1;
cout << Mac1;







  cout << endl << " Start programu " << endl << endl;
}

