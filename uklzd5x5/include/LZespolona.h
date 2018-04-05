#ifndef LZESPOLONA_H
#define LZESPOLONA_H
#include<iostream>
#include<cmath>

using namespace std;

class LZespolona
{
private:
double re;
double im;

    public:

double modul();
LZespolona sprzezenie();
LZespolona dzielenie_ZprzezR(double );
LZespolona  operator + ( LZespolona  );
LZespolona  operator - ( LZespolona  );
LZespolona  operator * ( LZespolona  );
LZespolona  operator / ( LZespolona  );
LZespolona operator *( double);
void operator=(LZespolona);
void operator=(double);
bool poruwnaj(LZespolona);
bool operator!=(LZespolona z2);
bool operator!=(int);
bool operator==(int);
void kopiuj(LZespolona&);
double daj_im()const{return im;}
double daj_re()const{return re;}
void zmien_im(double a){im=a;}
void zmien_re(double a){re=a;}
};
bool wczytaj(LZespolona&);
ostream& operator << (ostream &out, const LZespolona &Wynik);
istream& operator >> (istream &out, LZespolona &Wynik);
#endif // LZESPOLONA_H
