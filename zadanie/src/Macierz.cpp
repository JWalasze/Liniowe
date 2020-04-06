#include "Wektor.hh"
#include "Macierz.hh"
#include "cassert"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Macierz, ktore zawieraja wiecej kodu
 *  niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */



MacierzKw::MacierzKw(const Wektor tablica[])
  {
   this->tab[0]=tablica[0];
   this->tab[1]=tablica[1];
   this->tab[2]=tablica[2];
  }

MacierzKw::MacierzKw(Wektor A, Wektor B, Wektor C)
  {
   int i=0;
   this->tab[i]= A;
   this->tab[++i]= B;
   this->tab[++i]= C;
  }

const Wektor & MacierzKw::operator[] (int index) const
{
  return this->tab[index];
}

std::ostream& operator << (std::ostream &Strm, const MacierzKw &Mac)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Strm << Mac[j][i] << "  ";
        }
        Strm << endl;
    }
    return Strm;
}

std::istream& operator >> (std::istream &Strm, MacierzKw &Mac)
{
    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Strm >> Mac[i][j];
        }
    }
    return Strm;
}

Wektor & MacierzKw::operator[] (int index)
{
    assert(index < ROZMIAR && index >= 0);
    return this->tab[index];
}

const MacierzKw & MacierzKw::operator + (const MacierzKw & M2)
{
    Wektor tablica[ROZMIAR];
    for(int i=0; i<ROZMIAR; i++)
    {
        tablica[i] = this->tab[i] + M2[i];
    }
    MacierzKw Mac(tablica);
    MacierzKw &RefMac = Mac;
    return RefMac;
}

const MacierzKw & MacierzKw::operator - (const MacierzKw & M2)
{
    Wektor tablica[ROZMIAR];
    for(int i=0; i<ROZMIAR; i++)
    {
        tablica[i] = this->tab[i] - M2[i];
    }
    MacierzKw Mac(tablica);
    MacierzKw &RefMac = Mac;
    return RefMac;
}

const MacierzKw & MacierzKw::operator * (double l)
{
    Wektor tablica[ROZMIAR];
    for(int i=0; i<ROZMIAR; i++)
    {
        tablica[i] = this->tab[i] * l;
    }
    MacierzKw Mac(tablica);
    MacierzKw &RefMac = Mac;
    return RefMac;
}

const MacierzKw & MacierzKw::transponuj() const
{
    return *this;
}
void MacierzKw::transponuj()
{
    Wektor tablica[ROZMIAR];
    for(int j=0; j<ROZMIAR; j++)
    {
        for(int i=0; i<ROZMIAR; i++)
        {
            tablica[i][j] = this->tab[j][i];
        }
    }
    for(int j=0; j<ROZMIAR; j++)
    {
        for(int i=0; i<ROZMIAR; i++)
        {
           this->tab[i][j] = tablica[i][j];
        }
    }
}

const MacierzKw & MacierzKw::operator * (const MacierzKw & M2)
{
    MacierzKw W = *this;
    W.transponuj();

    Wektor tablica[ROZMIAR];

    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            tablica[j][i]= W[i] * M2[j];
        }
    }
    MacierzKw Mac(tablica);
    MacierzKw &RefMac = Mac;
    return RefMac;
}

const Wektor & MacierzKw::operator * (const Wektor & W2)
{
    double tablica[ROZMIAR];
    MacierzKw W1 = *this;
    W1.transponuj();

    for(int i=0; i<ROZMIAR; i++)
    {
        tablica[i]= W1[i] * W2;
    }
    Wektor W(tablica);
    Wektor & RefW = W;
    return RefW;
}

double MacierzKw::wyznacznik()
{
    double Wyzn = -1; //zmiana kolumn przy transponowaniu
    (*this).transponuj();
    for(int i = 1; i<ROZMIAR; i++)
    {
        this->tab[i] = this->tab[i] - ( ( this->tab[0] * this->tab[i][ROZMIAR-1] ) / this->tab[0][ROZMIAR-1] ) ;
        //cout << this->tab[i];
    }
    for(int i=ROZMIAR-1; i>1; i--)
    {
        this->tab[ROZMIAR-1] = this->tab[ROZMIAR-1] - ( ( this->tab[ROZMIAR-2] * this->tab[ROZMIAR-1][i-1] ) / this->tab[ROZMIAR-2][i-1] ) ;
        //cout << this->tab[ROZMIAR-1];
    }
    for(int i=0; i<ROZMIAR; i++)
    {
        Wyzn *= this->tab[i][ROZMIAR -1 -i];
    }
    return Wyzn;
}

int MacierzKw::rzad()
{
    double Wyzn = (*this).wyznacznik();
    if(Wyzn!=0)
    {
        cout << "Rzad macierzy rowny = " << ROZMIAR << endl;
    }
    else
    {
        cout << "Rzad macierzy mniejszy od " << ROZMIAR << endl;
    }
    return Wyzn;

}


