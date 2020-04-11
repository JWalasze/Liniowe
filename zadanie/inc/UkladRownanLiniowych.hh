#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include "Macierz.hh"
#include "Wektor.hh"


/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class UkladRownanLiniowych {
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich pol i metod prywatnych
   */
    MacierzKw A;
    Wektor b;
  public:
  /*
   *  Tutaj trzeba wstawic definicje odpowiednich metod publicznych
   */
    UkladRownanLiniowych();
    UkladRownanLiniowych(MacierzKw AA, Wektor bb) : A(AA), b(bb) {};

    const MacierzKw & get_A() const;
    const Wektor & get_b() const;

    void set_A(const MacierzKw & AA);
    void set_b(const Wektor & bb);

    Wektor Oblicz() const;
};


/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);

/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt
 */
std::ostream& operator << ( std::ostream                  &Strm,
                            const UkladRownanLiniowych    &UklRown
                          );


#endif
