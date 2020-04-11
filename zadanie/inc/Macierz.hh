#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include "Wektor.hh"
#include <iostream>


class MacierzKw {

    Wektor tab[ROZMIAR];

public:

    MacierzKw();

    MacierzKw(const Wektor tablica[]);

    MacierzKw(Wektor A, Wektor B, Wektor C);

    double wyznacznik() const;// rozwiniecje laplace'a, gaussa, sarrusa
  // double wyznacznikGauss(); double wyznacznik(metoda met = Gauss) <- enum
    int rzad();

    const MacierzKw & transponuj() const;
    void transponuj();

    const MacierzKw & odwroc() const;
    void odwroc();

    MacierzKw operator * (const MacierzKw & M2);
    MacierzKw operator + (const MacierzKw & M2);
    MacierzKw operator - (const MacierzKw & M2);
    MacierzKw operator * (double l);
    Wektor operator * (const Wektor & W2);

    const Wektor & operator[] (int index) const;//wg. 2. propozycji
    Wektor & operator[] (int index); // M[2][0] - zerowy element, drugiego wektora

    const MacierzKw & zamien_kolumny() const;
    void zamien_kolumny();

  //const Wektor & zwroc_kolumne(int ind); //dla interpretacji wierszowej
  //void zmien_kolumne(int ind, Wektor W); //dla interpretacji wierszowej

};

std::istream& operator >> (std::istream &Strm, MacierzKw &Mac);

std::ostream& operator << (std::ostream &Strm, const MacierzKw &Mac);

#endif
