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
   this->tab[0]=0;
   this->tab[1]=0;
   this->tab[2]=0;
}

Wektor::Wektor(double tablica[])
   {
   this->tab[0]=tablica[0];
   this->tab[1]=tablica[1];
   this->tab[2]=tablica[2];
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

const Wektor & Wektor::operator + (const Wektor & W2) const
 {
    double tablica[ROZMIAR];

    for(int i=0; i<ROZMIAR; i++)
    {
    tablica[i]=this->tab[i] + W2[i];
    }
    Wektor W1(tablica);
    Wektor & RefW = W1;
    return RefW;
 }

const Wektor & Wektor::operator - (const Wektor & W2) const
{
   double tablica[ROZMIAR];

   for(int i=0; i<ROZMIAR; i++)
   {
   tablica[i]=this->tab[i] - W2[i];
   }
   Wektor W1(tablica);
   Wektor & RefW = W1;
   return RefW;
}

const Wektor & Wektor::operator * (double l) const
{
   double tablica[ROZMIAR];

   for(int i=0; i<ROZMIAR; i++)
   {
   tablica[i]=this->tab[i] * l;
   }
   Wektor W1(tablica);
   Wektor & RefW = W1;
   return RefW;
}

const Wektor & Wektor::operator / (double l) const
{
   double tablica[ROZMIAR];

   for(int i=0; i<ROZMIAR; i++)
   {
   tablica[i]=this->tab[i] / l;
   }
   Wektor W1(tablica);
   Wektor & RefW = W1;
   return RefW;
}

bool Wektor::operator == (const Wektor & W2) const
{
   if(this->tab[0]==W2[0] && this->tab[1]==W2[1] && this->tab[2]==W2[2])
   {
   return true;
   }
   else
   {
   return false;
   }
}

bool Wektor::operator != (const Wektor & W2) const
{
   if(this->tab[0]==W2[0] && this->tab[1]==W2[1] && this->tab[2]==W2[2])
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
   Strm << Wek[i] << "  ";
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
   return Wektor(W2)*l;
}



