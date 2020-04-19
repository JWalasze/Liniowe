#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <cmath>

using namespace std;


class Wektor {

    double tab[ROZMIAR];

  public:

    Wektor();

    Wektor(double tablica[]);

    Wektor(double x, double y, double z);

    Wektor operator + (const Wektor & W2) const;
    Wektor operator - (const Wektor & W2) const;
    Wektor operator * (double l) const;
    double operator * (const Wektor & W2) const; //skalarnie
    Wektor operator / (double l) const;

    double dlugosc() const;

    bool operator == (const Wektor & W2) const;
    bool operator != (const Wektor & W2) const;

    const double & operator [] (int index) const;
    double & operator [] (int index);

    const Wektor & zamien_kolumny() const;
    void zamien_kolumny();
};

Wektor operator * (double l, Wektor W2);

std::istream & operator >> (std::istream &Strm, Wektor &Wek);

std::ostream & operator << (std::ostream &Strm, const Wektor &Wek);

#endif
