#include "Macierz.h"
using namespace std;





template<typename T,int rozm>
ostream& operator<< (ostream&Strm, const Macierz<T,rozm> &Mac){

  for(int i=0; i<rozm; ++i){
    Strm<<Mac[i];
Strm<<endl;
  }
return Strm;
}
template<typename T,int rozm>
istream& operator >> (istream &in, Macierz<T,rozm> &Mac){

  for(int i=0; i<rozm; ++i){
    in>> Mac[i];

  }
  Mac.transponowanie();
return in;

}
template<typename T,int rozm>
inline void Macierz<T,rozm>:: kopiuj(Macierz<T,rozm>  &a){
  for(int i=0; i<rozm; ++i){
    for(int j=0; j<rozm; ++j){
      a[i][j]=this->tab[i][j];}
}
}

template<typename T,int rozm>
inline void const Macierz<T,rozm>:: kopiuj(Macierz<T,rozm>  &a)const{
  for(int i=0; i<rozm; ++i){
    for(int j=0; j<rozm; ++j){
      a[i][j]=this->tab[i][j];}
}
}



template<typename T,int rozm>
void kopiuj(Macierz<T,rozm> b,Macierz<T,rozm> &a){
  for(int i=0; i<rozm; ++i){
    for(int j=0; j<rozm; ++j){
      a[i][j]=b[i][j];
}
}

}
template<typename T,int rozm>
inline void Macierz<T,rozm>:: transponowanie(){
Macierz<T,rozm> a;
kopiuj(a);//do macierzy a

  for(int i=0; i<rozm; ++i)
    for(int j=0; j<rozm; ++j)
      this->tab[i][j]=a[j][i];

}



template<typename T,int rozm>
void transponowanie(Macierz<T,rozm> &a){
Macierz<T,rozm> b;
kopiuj(a,b);

for(int i=0; i<rozm; ++i)
    for(int j=0; j<rozm; ++j)
      a[i][j]=b[j][i];



}
template<typename T,int rozm>
inline void Macierz<T,rozm>:: zamiana(int i,Wektor<T,rozm> &b){
Wektor<T,rozm> a;
a=b;
transponowanie();
b=this->tab[i];
this->tab[i]=a;
transponowanie();

}


template<typename T,int rozm>
inline const T Macierz<T,rozm>:: gaus()const{
Macierz<T,rozm> a;
kopiuj(a);
T t,y,wynik;
double wsp=1;
wynik=1;
double i,k,j;
for (i=0; i<rozm; ++i) {
for (k=i+1; k<rozm; ++k){
if(a[i][i]!=0){
t=a[k][i]/a[i][i];}else{a.transponowanie(); a.zamiana(i,a[k]); wsp*=-1; a.transponowanie(); i=0; j=0;}

for (j=0;j<=rozm;++j){
y=a[i][j]*t;
a[k][j]=a[k][j]-y;
}
}
}
for(i=0; i<rozm; ++i){
    wynik=a[i][i]*wynik;

}
wynik=wynik*wsp;
return wynik;
}
/*
double Macierz:: sarus(){
Macierz a;
kopiuj(a);
return a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]-a[2][0]*a[1][1]*a[0][2]-a[2][1]*a[1][2]*a[0][0]-a[2][2]*a[1][0]*a[0][1];
}
*/

