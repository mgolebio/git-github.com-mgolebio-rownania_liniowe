#ifndef WEKTOR_H
#define WEKTOR_H
#include<iostream>
#include"LZespolona.h"

using namespace std;

template <typename T,int rozm>
class Wektor {

  T wek[rozm];

  public:
Wektor();

T wez(int i)const{return wek[i];}

void daj(int i,T a){wek[i]=a;}

  T &operator[](int i){return wek[i];}
  const T &operator[](int i)const{return wek[i];}


inline  Wektor<T,rozm> operator /(T);
inline  Wektor<T,rozm> operator*(T);
 inline Wektor<T,rozm> operator+(Wektor<T,rozm>);
 inline Wektor<T,rozm> operator-(Wektor<T,rozm>);
inline T operator/(Wektor<T,rozm>);
inline  Wektor<T,rozm> operator*(Wektor<T,rozm>);
inline void operator=(Wektor<T,rozm>);
inline double modul();



};
template<typename T,int rozm>
ostream& operator << (ostream &Strm,const Wektor<T,rozm> &Wek){
int i;

 for( i=0; i<rozm; ++i){
Strm<<Wek.wez(i)<<" ";
}
return Strm;
}

template<typename T,int rozm>
istream& operator>>(istream &in, Wektor<T,rozm> &Wek){
T x;
for(int i=0; i<rozm; ++i){
in>>x;
Wek.daj(i,x);
}
return in;
}

template <typename T,int rozm>
bool wczytaj(Wektor<T,rozm>&);

#endif // WEKTOR_H
