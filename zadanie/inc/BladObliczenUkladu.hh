#ifndef BLADOBLICZENUKLADU_HH
#define BLADOBLICZENUKLADU_HH

#include "rozmiar.h"
#include <iostream>
#include <cmath>
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "Wektor.hh"


using namespace std;

double DlugoscWektoraBledu(Wektor W);

Wektor WektorBledu(UkladRownanLiniowych Ukl);

#endif
