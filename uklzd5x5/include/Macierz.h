#ifndef MACIERZ_H
#define MACIERZ_H
#include"Wektor.hh"
template<typename T,int rozm>
class Macierz
{
    public:


inline  void kopiuj(Macierz<T,rozm>&);
inline const void kopiuj(Macierz<T,rozm>&)const;
inline  void transponowanie();
inline void zamiana(int,Wektor<T,rozm>&);
inline const T gaus()const;

inline Wektor<T,rozm>& operator[](int a){return this->tab[a];}
inline const Wektor<T,rozm>& operator[](int i)const{return tab[i];}
inline Macierz<T,rozm> operator=(Macierz<T,rozm> b);
    private:

    Wektor<T,rozm> tab[rozm];


};
template<typename T,int rozm>
void kopiuj(Macierz<T,rozm>,Macierz<T,rozm>&);
template<typename T,int rozm>
void transponowanie(Macierz<T,rozm>&);
template<typename T,int rozm>
std::istream& operator >> (std::istream &, Macierz<T,rozm> &);
template<typename T,int rozm>
std::ostream& operator << (std::ostream &, const Macierz <T,rozm>&);


#endif
