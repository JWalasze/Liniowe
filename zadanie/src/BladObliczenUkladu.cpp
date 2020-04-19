#include "BladObliczenUkladu.hh"

Wektor WektorBledu(UkladRownanLiniowych Ukl)
{
    Wektor WynikUkl = Ukl.Oblicz();
    Wektor WynikBledu = Ukl.get_A() * WynikUkl - Ukl.get_b();

    return WynikBledu;
}

double DlugoscWektoraBledu(Wektor W)
{
    double Wynik;
    Wynik = sqrt(W*W);

    return Wynik;
}
