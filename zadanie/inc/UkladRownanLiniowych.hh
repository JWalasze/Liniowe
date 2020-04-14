#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <fstream>
#include "Macierz.hh"
#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {

    MacierzKw A;
    Wektor b;

  public:

    UkladRownanLiniowych()
    {
        b = Wektor();
        A = MacierzKw();
    }
    UkladRownanLiniowych(MacierzKw AA, Wektor bb)
    {
        A = AA;
        b = bb;
    }

    MacierzKw get_A() const;
    Wektor get_b() const;

    void set_A(const MacierzKw & AA);
    void set_b(const Wektor & bb);

    Wektor Oblicz() const;
};

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown );

#endif
