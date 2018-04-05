#include <iostream>
#include"LZespolona.h"
#include"Wektor.hh"
#include"Wektor.cpp"
#include"Macierz.h"
#include"Macierz.cpp"
#include"UkladRownan.hh"
#include"UkladRownan.cpp"
#include"windows.h"
using namespace std;

int main(int argc, char *argv[])
{
bool wczytanie=false;

if(argv[1][0]!='-'){
        cout<<"nie poprawna opcja wywolania"<<endl;
return 1;
}
    switch(argv[1][1]){
case 'z':
    {

cout<<endl;
UkladRownan<LZespolona,5> A;
A.wczytaj(wczytanie);
if(wczytanie!=false){
        system("cls");
        A.wypisz();
}

break;
    }
case 'r' :{
    UkladRownan<double,5> B;
    B.wczytaj(wczytanie);
    if(wczytanie!=false){
            system("cls");
        B.wypisz();
    }
    break;
}
    default :{ cout<<"nie podano argumnetu wywolania"<<endl;

     break;}

    }
    return 0;
}
