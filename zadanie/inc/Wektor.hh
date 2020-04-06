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

   const Wektor & operator + (const Wektor & W2) const;
   const Wektor & operator - (const Wektor & W2) const;
   const Wektor & operator * (double l) const;
   double operator * (const Wektor & W2) const; //skalarnie
   const Wektor & operator / (double l) const;

   double dlugosc() const;

   bool operator == (const Wektor & W2) const;
   bool operator != (const Wektor & W2) const;

   const double & operator [] (int index) const;
   double & operator [] (int index);
};

Wektor operator *(double l, Wektor W2);


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, Wektor &Wek);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);




#endif
