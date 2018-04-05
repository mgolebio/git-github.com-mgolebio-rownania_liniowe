#include "LZespolona.h"
double LZespolona:: modul(){
double suma=pow(this->re,2)+pow(this->im,2);
return sqrt(suma);

}

LZespolona LZespolona:: sprzezenie(){
  LZespolona Wynik;
  Wynik.re=this->re;
  Wynik.im=-1*this->im;
  return Wynik;
}
LZespolona LZespolona:: dzielenie_ZprzezR(double a){
  LZespolona w;
  w.re=this->re/a;
  w.im=this->im/a;
  return w;
}

LZespolona LZespolona:: operator + ( LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = this->re + Skl2.re;
  Wynik.im = this->im + Skl2.im;
  return Wynik;
}

 LZespolona LZespolona :: operator - ( LZespolona z2){

   LZespolona W;
   W.re=this->re-z2.re;
   W.im=this->im-z2.im;
   return W;

 }
 LZespolona LZespolona:: operator * ( LZespolona z2){
   LZespolona w;
   w.re=this->re*z2.re-(this->im*z2.im);
   w.im=this->re*z2.im+(this->im*z2.re);
   return w;
 }

void LZespolona:: kopiuj(LZespolona& a){
a.re=this->re;
a.im=this->im;

}
LZespolona LZespolona::  operator / (LZespolona z2){

  LZespolona Wynik;
  LZespolona a;
  this->kopiuj(a);
  double b=z2.modul();
  double c=pow(b,2);
  a=a*z2.sprzezenie();
  Wynik=a.dzielenie_ZprzezR(c);
  return Wynik;
}
 LZespolona LZespolona:: operator*(double x){
    LZespolona w;

w.re*=this->re*x;
w.im*=this->im*x;
return w;
}

bool LZespolona:: operator!=(LZespolona z2){
if(this->re!=z2.re || this->im!=z2.im){return true;}
else
return false;
}
bool LZespolona:: operator!=(int x){
if(this->re!=x || this->im!=x){return true;}
else
return false;
}
bool LZespolona:: operator==(int x){
if(this->re==x && this->im==x){return true;}
else return false;
}

bool LZespolona:: poruwnaj( LZespolona z2){
  if(this->re==z2.re && z2.im==this->im)return true;
  else return false;

}

void LZespolona:: operator=(LZespolona z2){
this->re=z2.re;
this->im=z2.im;

}
void LZespolona:: operator=(double x){
this->re=x;
this->im=x;
}
ostream& operator << (ostream& out, const LZespolona &Wynik){
double x=Wynik.daj_re();
double y=Wynik.daj_im();

  out<<"("<<x<<showpos<<y<<noshowpos<<"i)";
  return out;
}
istream& operator >> (istream& in, LZespolona &wynik){
  char tab[3];
double x;
  cin>>tab[0];
  if(tab[0]!='('){in.setstate(ios::failbit);

    return in;}
  cin>>x;
  wynik.zmien_re(x);
  cin>>x;
  wynik.zmien_im(x);
  cin>>tab[1];
  if(tab[1]!='i'){in.setstate(ios::failbit);
         return in;}
  cin>>tab[2];
  if(tab[2]!=')'){in.setstate(ios::failbit);
    return in;}



  return in;
}
bool wczytaj(LZespolona &L){
  int i;
  for( i=3; i>0; --i){
  cin>>L;
  if(cin.fail()){
    cin.clear();
    cin.ignore(10000, '\n');
  }else break;
  }

  if(i==0)return false;
  else return true;

}
