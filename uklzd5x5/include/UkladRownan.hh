#ifndef UKLADROWNAN_H
#define UKLADROWNAN_H
#include"Macierz.h"
#include"Wektor.hh"
template<typename T,int rozm>
class UkladRownan
{
Macierz<T,rozm> Rownanie;
Wektor<T,rozm> Wwolne;
public:
void wczytaj(bool&);
void wypisz();
Wektor<T,rozm> oblicz(bool&,bool&);
void rezultat();

};

#endif // UKLADROWNAN_H
