#include "UkladRownan.hh"
#include"windows.h"
#include"iostream"
#include"stdlib.h"
using namespace std;
template<typename T,int rozm>
void UkladRownan<T,rozm> :: wczytaj(bool &x){
cout<<"podaj wartosci wspolczynnikow"<<endl;
for(int i=0; i<3; ++i){

    cin>>Rownanie;
 if(cin.fail()){
    cin.clear();
    cin.ignore(10000,'\n');
}
else break;
}
if(cin.fail()){cout<<"wczytanie nie udane"<<endl; x=false; return;}else {x=true;}

cout<<endl;
cout<<"wyrazy wolne:"<<endl;
for(int i=0; i<3; ++i){
    cin>>Wwolne;
 if(cin.fail()){
    cin.clear();
    cin.ignore(10000,'\n');
}
else break;
}
if(cin.fail()){cout<<"wczytanie nie udane"<<endl; x=false;}

}
template<typename T,int rozm>
void UkladRownan<T,rozm>::wypisz(){
    int i;
bool inft=false;
bool sprzecz=false;
Wektor<T,rozm> wek;
wek=this->oblicz(inft,sprzecz);


for(i=0; i<rozm; ++i){
        cout<<"|";

    for(int j=0; j<rozm; ++j){
    if(j<rozm){
    cout.width( 5 );
    cout<<Rownanie[i][j];
    }
    if(j==rozm-1){
        cout.width(5);
        cout<<"|";
        cout.width( 10 );
        cout<<"|";
        cout.width(2);
        cout<<Wwolne[i];
        cout.width(2);
        cout<<"|";
        cout.width(10);
       if(inft==true && sprzecz==false)cout<<"inft";
        else if(sprzecz==true && inft==false)cout<<"brak";
        else if(inft==false && sprzecz==false)cout<<wek[i];
    }
    }
cout<<endl;
}

}
template<typename T,int rozm>
Wektor<T,rozm> UkladRownan<T,rozm>:: oblicz(bool &inft,bool &sprzecz){
    Macierz<T,rozm> A;
    Rownanie.kopiuj(A);
    Wektor<T,rozm> W;
    T G,x; //G- glowna
    int ile_zer=0;
inft=false;
sprzecz=false;
    G=A.gaus();
    cout<<G<<endl;
for(int i=0; i<rozm; ++i){
    A.zamiana(i,Wwolne);
    cout<<A;
    x=A.gaus();
    cout<<endl<<x<<endl;
    if(G!=0){
    x=x/G;
    W.daj(i,x);
    }
    if(x==0){++ile_zer;}
    A.zamiana(i,Wwolne);
}
if(ile_zer==rozm && G==0)inft=true;
else if(ile_zer!=rozm && G==0)sprzecz=true;
return W;
}

template<typename T,int rozm>
void UkladRownan<T,rozm>:: rezultat(){
    Wektor<T,rozm> L;
    bool inf=false;
    bool sprz=false;
    L=this->oblicz(inf,sprz);
    cout<<"\tWyniki"<<endl;
    if(sprz!=false && inf!=false){
cout<<L<<endl;}
else if(sprz==true && inf==false)cout<<"brak"<<endl;
else if(sprz== false && inf==true)cout<<"nieskonczenie wiele"<<endl;
}


