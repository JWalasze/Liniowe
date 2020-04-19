#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "Wektor.hh"
#include "BladObliczenUkladu.hh"


using namespace std;

int main()
{
    cout << "Start programu" << endl;

    std::fstream plik;
    plik.open("plik.txt");

    if( plik.good()==false )
    {
        cout << "Brak takiego pliku" << endl;
        exit(0);
    }
    MacierzKw Macierz;
    Wektor Wek;
    plik >> Macierz >> Wek;
    plik.close();

    UkladRownanLiniowych Ukl;
    Ukl.set_A(Macierz);
    Ukl.set_b(Wek);
    cout << endl << "Macierz wspolczynnikow - A" << endl;
    cout << Ukl.get_A() << endl;

    cout << "Wektor wyrazow wolnych - b" << endl;
    cout << Ukl.get_b() << endl;

    Wektor Wynik = Ukl.Oblicz();

    cout << "Rozwiazanie x = (x1, x2, x3):" << endl;
    cout << Wynik << endl;

    cout << "Wektor bledu: Ax-b = " << WektorBledu(Ukl) << endl;
    cout << "Dlugosc wektora bledu: ||Ax-b|| = " << DlugoscWektoraBledu(WektorBledu(Ukl)) << endl;

}

