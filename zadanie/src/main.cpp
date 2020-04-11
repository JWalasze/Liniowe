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

  Wektor W1(2,-2,-2);
  Wektor W3(5,2,3);
  Wektor W4(-1,3,4);
  Wektor W5(1,4,5);
  Wektor W6(9,8.5,8);
  Wektor W7(1,4,1);
  Wektor W8(2,3,1);

  Wektor W9(1,1,1);
  Wektor W10(-2,8,4);
  Wektor W11(9,8.5,8);

  MacierzKw M(W1,W3,W4);
  cout << M << endl;
  M.odwroc();
  cout << M << endl;
  Wektor W = M * W10;
  cout << W;











}

