#ifndef SZYBKI_HH
#define SZYBKI_HH

#include<iostream>
#include<cstdlib>




template<class T, int ilosc>
class Szybkie  
{
    public:

    T *tablica = new T [ilosc];
    //Szybkie();

    void wyswietlTablice();
    void wypelnijLosowymiLiczbami ();
    void szybkiSortowanie(int poczatek , int koniec);

};







#endif