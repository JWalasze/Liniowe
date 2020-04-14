#include "Wektor.hh"
#include "cassert"

/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Wektor, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

Wektor::Wektor()
{
   for(int i=0; i<ROZMIAR; i++)
    {
        this->tab[i]=0;
    }
}

Wektor::Wektor(double tablica[])
{
    for(int i=0; i<ROZMIAR; i++)
    {
        this->tab[i]=tablica[i];
    }
}

Wektor::Wektor(double x, double y, double z)
   {
   int i=0;
   this->tab[i]=x;
   this->tab[++i]=y;
   this->tab[++i]=z;
   }

const double & Wektor::operator[](int index) const
{
  return this->tab[index];
}

double & Wektor::operator [] (int index)
{
    assert(index < ROZMIAR && index >= 0);
    return this->tab[index];
}

double Wektor::dlugosc() const
{
   double Wynik = 0;

   for(int i=0; i<ROZMIAR; i++)
   {
   Wynik += pow(this->tab[i],2);
   }
   return sqrt(Wynik);
}

double Wektor::operator * (const Wektor & W2) const //SKALARNIE
{
   double Wynik = 0;

   for(int i=0; i<ROZMIAR; i++)
   {
   Wynik += this->tab[i] * W2[i];
   }
   return Wynik;
}

Wektor Wektor::operator + (const Wektor & W2) const
{
    Wektor Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        Wynik[i]=this->tab[i] + W2[i];
    }
    return Wynik;
}

Wektor Wektor::operator - (const Wektor & W2) const
{
    Wektor Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        Wynik[i]=this->tab[i] - W2[i];
    }
    return Wynik;
}

Wektor Wektor::operator * (double l) const
{
    Wektor Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        Wynik[i]=this->tab[i] * l;
    }
    return Wynik;
}

Wektor Wektor::operator / (double l) const
{
    Wektor Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        assert(l!=0);
        Wynik[i]=this->tab[i] / l;
    }
    return Wynik;
}

bool Wektor::operator == (const Wektor & W2) const
{
    for(int i=0; i<ROZMIAR; i++)
    {
        if( this->tab[i]!= W2[i])
        {
            return false;
        }
    }
    return true;
}

bool Wektor::operator != (const Wektor & W2) const
{
   if(*this==W2)
   {
   return false;
   }
   else
   {
   return true;
   }
}

std::ostream& operator << (std::ostream &Strm, const Wektor &Wek)
{
   for(int i=0; i<ROZMIAR; i++)
   {
   Strm << Wek[i] << " ";
   }
   Strm << endl;
   return Strm;
}

std::istream& operator >> (std::istream &Strm, Wektor &Wek)
{
   for(int i=0; i<ROZMIAR; i++)
   {
   Strm >> Wek[i];
   }
   return Strm;
}

Wektor operator * (double l, Wektor W2)
{
   return W2*l;
}
