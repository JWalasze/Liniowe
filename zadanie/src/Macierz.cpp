#include "Wektor.hh"
#include "Macierz.hh"
#include "cassert"

using namespace std;

MacierzKw::MacierzKw()
{
    for(int i=0; i<ROZMIAR; i++)
    {
        this->tab[i]= Wektor();
    }
}

MacierzKw::MacierzKw(const Wektor tablica[])
  {
    for(int i=0; i<ROZMIAR; i++)
    {
        this->tab[i]=tablica[i];
    }
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

Wektor & MacierzKw::operator[] (int index)
{
    assert(index < ROZMIAR && index >= 0);
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
        Strm >> Mac[i];
    }
    return Strm;
}

MacierzKw MacierzKw::operator + (const MacierzKw & M2) const
{
    MacierzKw Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] + M2[i];
    }
    return Wynik;
}

MacierzKw MacierzKw::operator - (const MacierzKw & M2) const
{
    MacierzKw Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] - M2[i];
    }
    return Wynik;
}

MacierzKw MacierzKw::operator * (double l) const
{
    MacierzKw Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        Wynik[i] = this->tab[i] * l;
    }
    return Wynik;
}

const MacierzKw & MacierzKw::transponuj() const
{
    return *this;
}
void MacierzKw::transponuj()
{
    for(int j=0; j<ROZMIAR; j++)
    {
        for( int i=j; i<ROZMIAR; i++)
        {
            swap( this->tab[i][j], this->tab[j][i] );
        }
    }
}

MacierzKw MacierzKw::operator * (const MacierzKw & M2) const
{
    MacierzKw Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        for(int j=0; j<ROZMIAR; j++)
        {
            Wynik[j][i]= this->tab[i] * M2[j];
        }
    }
    return Wynik;
}

Wektor MacierzKw::operator * (const Wektor & W2) const
{
    Wektor Wynik;
    for(int i=0; i<ROZMIAR; i++)
    {
        Wynik[i]= this->tab[i] * W2;
    }
    return Wynik;
}

double MacierzKw::wyznacznik() const
{
    double Wyzn = 1;
    MacierzKw M = *this;
    for(int i = 1; i<ROZMIAR; i++)
    {
        if( M[0][ROZMIAR-1]==0 )
        {
            M[0] = M[0] + M[i];
        }
        M[i] = M[i] - ( ( M[0] * M[i][ROZMIAR-1] ) / M[0][ROZMIAR-1] );

        if( i>1 )
        {
            for( int x = ROZMIAR - 2; x>=ROZMIAR-i; x--)
            {
                int stala=i;
                if( M[stala-1][x]==0 )
                {
                    cout << "Wyznacznik jest rowny zero" << endl << "Macierz osobliwa" << endl;
                    return 0;
                }

                M[stala] = M[stala] - ( ( M[stala-1] * M[stala][x] ) / M[stala-1][x] );
            }
        }
    }
    for(int i=0; i<ROZMIAR; i++)
    {
        Wyzn *= M[i][ROZMIAR -1 -i];
    }

    double x = ROZMIAR / 2;
    int zrzut = static_cast<int>(x);
    if( zrzut%2==0 || zrzut==1 )
    {
        return -1*Wyzn;
    }
    else
    return Wyzn;
}

int MacierzKw::rzad() const
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

const MacierzKw & MacierzKw::odwroc() const
{
    return *this;
}

void MacierzKw::odwroc()
{
    if((*this).wyznacznik()==0)
    {
        cerr << "Nie mozna policzyc macierzy odwrotnej" << endl;
        cout << "Wyznacznik jest rowny 0!" << endl;
        exit(0);
    }
    MacierzKw Odwr;
    (*this).zamien_kolumny();
    for(int i=0; i<ROZMIAR; i++)
    {
        Odwr[i][ROZMIAR-1-i] = 1;
    }
    for(int i = 1; i<ROZMIAR; i++)
    {
        if( this->tab[0][ROZMIAR-1]==0 )
        {
            this->tab[0] = this->tab[0] + this->tab[i];
            Odwr[0] = Odwr[0] + Odwr[i];
        }
        Odwr[i] = Odwr[i] - ( ( Odwr[0] * this->tab[i][ROZMIAR-1] ) / this->tab[0][ROZMIAR-1] );
        this->tab[i] = this->tab[i] - ( ( this->tab[0] * this->tab[i][ROZMIAR-1] ) / this->tab[0][ROZMIAR-1] );
        if( i>1 )
        {
            for( int x = ROZMIAR - 2; x>=ROZMIAR-i; x--)
            {
                int stala=i;
                Odwr[stala] = Odwr[stala] - ( ( Odwr[stala-1] * this->tab[stala][x] ) / this->tab[stala-1][x] );
                this->tab[stala] = this->tab[stala] - ( ( this->tab[stala-1] * this->tab[stala][x] ) / this->tab[stala-1][x] );
            }
        }
    }

    for(int i=0; i<ROZMIAR; i++)
    {
        Odwr[i] = Odwr[i] / this->tab[i][ROZMIAR-1-i];
        this->tab[i] = this->tab[i] / this->tab[i][ROZMIAR-1-i];
    }

    //drugi trojkat

    for(int i=ROZMIAR-2; i>=0; i--)
    {
        Odwr[i] = Odwr[i] - ( ( Odwr[ROZMIAR-1] * this->tab[i][0] ) / this->tab[ROZMIAR-1][0] );
        this->tab[i] = this->tab[i] - ( ( this->tab[ROZMIAR-1] * this->tab[i][0] ) / this->tab[ROZMIAR-1][0] );
        if( i<ROZMIAR-2 )
        {
            for( int x = 1; x<=ROZMIAR-2; x++)
            {
                int stala=i;
                Odwr[stala] = Odwr[stala] - ( ( Odwr[stala+1] * this->tab[stala][x] ) / this->tab[stala+1][x] );
                this->tab[stala] = this->tab[stala] - ( ( this->tab[stala+1] * this->tab[stala][x] ) / this->tab[stala+1][x] );
            }
        }
    }
    *this=Odwr;
}

void MacierzKw::zamien_kolumny()
{
    for(int i=0; i<ROZMIAR/2; i++)
    {
        swap( this->tab[i], this->tab[ROZMIAR-1-i] );
    }
}

const MacierzKw & MacierzKw::zamien_kolumny() const
{
    return *this;
}





