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
    std::fstream plik;
    plik.open("plik.txt");

    if( plik.good()==false )
    {
        cout << "Brak takiego pliku" << endl;
        exit(0);
    }
    MacierzKw Macierz;
    plik >> Macierz;
    plik.close();
    return Macierz;
}

Wektor UkladRownanLiniowych::get_b() const
{
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
    return Wek;
}

Wektor UkladRownanLiniowych::Oblicz() const
{
    MacierzKw OdwrA = this->A;
    Wektor Wek = this->b;
    OdwrA.odwroc();
    Wektor Wynik;

    Wynik = OdwrA * Wek;

    return Wynik;
}

std::ostream& operator << ( std::ostream &Strm, const UkladRownanLiniowych &UklRown )
{
    Strm << UklRown.get_A() << endl;
    Strm << UklRown.get_b() << endl;
    return Strm;
}







