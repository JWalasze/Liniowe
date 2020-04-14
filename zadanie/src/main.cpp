#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "Wektor.hh"


using namespace std;

int main()
{
  cout << "Start programu" << endl;

  UkladRownanLiniowych Ukl;
  MacierzKw Mac = Ukl.get_A();
  cout << endl << "Macierz wspolczynnikow - A" << endl;
  cout << Mac << endl;

  Wektor Wek = Ukl.get_b();
  cout << "Wektor wyrazow wolnych - b" << endl;
  cout << Wek << endl;

  Ukl.set_A(Mac);
  Ukl.set_b(Wek);

  Wektor Wynik = Ukl.Oblicz();

  cout << "Rozwiazanie x = (x3, x2, x1):" << endl;
  cout << Wynik;

}

