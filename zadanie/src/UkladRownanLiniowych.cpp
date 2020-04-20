#include "UkladRownanLiniowych.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy UkladRownanLiniowych, ktore zawieraja
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

void UkladRownanLiniowych::set_A(const MacierzKw & AA)
{
    this->A = AA;
}

void UkladRownanLiniowych::set_b(const Wektor & bb)
{
    this->b = bb;
}

MacierzKw UkladRownanLiniowych::get_A() const
{
    return this->A;
}

Wektor UkladRownanLiniowych::get_b() const
{
    return this->b;
}

Wektor UkladRownanLiniowych::Oblicz() const
{
    MacierzKw OdwrA = this->A;
    Wektor Wek = this->b;
    OdwrA.odwroc();
    Wektor Wynik;

    Wynik = OdwrA * Wek;
    Wynik.zamien_kolumny();

    return Wynik;
}

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown )
{
    Strm << UklRown.get_A() << endl;
    Strm << UklRown.get_b() << endl;
    return Strm;
}

std::istream& operator >> ( std::istream &Strm, UkladRownanLiniowych &UklRown )
{
    MacierzKw M;
    Wektor W;
    Strm >> M >> W;
    UklRown.set_A(M);
    UklRown.set_b(W);
    return Strm;
}

