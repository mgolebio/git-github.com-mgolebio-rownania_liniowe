#include "Wektor.hh"
#include"windows.h"
using namespace std;

template<typename T,int rozm>
inline Wektor<T,rozm> Wektor<T,rozm> :: operator+(Wektor <T,rozm>w2){
  Wektor<T,rozm> tmp;



    for(int i=0; i<rozm; ++i)
      {
     tmp[i]= this->wek[i]+w2[i];
      }

 return tmp;
}



template<typename T,int rozm>
inline Wektor<T,rozm> :: Wektor()
{
for(int i=0; i<rozm; ++i)wek[i]=0;

}
template<typename T,int rozm>
inline Wektor<T,rozm> Wektor<T,rozm>:: operator *(Wektor<T,rozm> w2){
  Wektor<T,rozm> tmp;
for(int i=0; i<rozm; ++i)
{
tmp[i]=this->wek[i]*w2[i];
}
return tmp;
}
//template Wektor<double,3> Wektor<double,3>::operator*(Wektor<double,3> );

template<typename T,int rozm>
inline T Wektor<T,rozm>::operator /(Wektor<T,rozm> w2){
  int i,h=0;
  T k;

     k=this->wek[0]/w2[0];
    for( i=1; i<rozm; ++i){
      if(k!=this->wek[i]/w2.wek[i]){++h; break;}}


  if(h==0 )return k;
}

//template double Wektor<double,3>::operator/(Wektor<double,3> );

template<typename T,int rozm>
inline Wektor<T,rozm> Wektor<T,rozm> ::operator - (Wektor<T,rozm> w2){
  Wektor<T,rozm> tmp;

    for(int i=0; i<rozm; ++i)
      {
      tmp[i]=this->wek[i]-w2[i];
      }

    return tmp;
}
//template Wektor<double,3> Wektor<double,3>::operator-(Wektor<double,3> );

template<typename T,int rozm>
inline Wektor<T,rozm> Wektor<T,rozm>:: operator * (T a){
  Wektor <T,rozm>tmp;
  for(int i=0; i<rozm; ++i){
    tmp[i]=this->wek[i]*a;
  }
  return tmp;
}
//template Wektor<double,3> Wektor<double,3>::operator*(double);

template<typename T,int rozm>
inline Wektor<T,rozm> Wektor<T,rozm>:: operator /(T){
  Wektor<T,rozm> tmp;
  T a;
  for(int i=0; i<rozm; ++i){

   tmp[i]= this->wek[i]/a;

  }

return tmp;
}
//template Wektor<double,3> Wektor<double,3>::operator/(double );

template<typename T,int rozm>
inline void Wektor<T,rozm>:: operator= ( Wektor<T,rozm> w){
for (int i=0; i<rozm; ++i){this->wek[i]=w.wek[i];}


}


template<typename T,int rozm>
 bool wczytaj(Wektor<T,rozm> &w){
  int i;
  for( i=3; i>0; --i){
  cin>>w;
  if(cin.fail()){
    cin.clear();
    cin.ignore(10000, '\n');
    if(i!=0){cout<<"napisz wektor od nowa"<<endl;}
else {cout<<"wczytanie nie udane"<<endl;}
  }else break;
  }

  if(i==0)return false;
  else return true;

}

