#include<iostream>
#include<cstdlib>
#include"szybki.hh"


using namespace std;



/*
template<class T, int ilosc>
Szybkie<T, ilosc>::Szybkie()
{
    srand(time(NULL));
   for(int i = 0; i < ilosc ; i++)
   {
       tablica[i] = rand() % 100;
   }

}*/


template<class T, int ilosc>
void Szybkie<T, ilosc>::szybkiSortowanie(int poczatek , int koniec)
{
   
    int i = poczatek;
    int j = koniec;
    int pomocniczy;
    int srodek = tablica[ (poczatek+koniec) / 2];

    while(i <= j)
    {
        while(tablica[i] < srodek)
            i++;
        
        while(tablica[j] > srodek)
            j--;
        
        if(i <= j)
        {
            pomocniczy = tablica[i];
            tablica[i] = tablica[j];
            tablica[j] = pomocniczy;
            i++;
            j--;


        }


    };
    
    
    if(poczatek < j)
        szybkiSortowanie(poczatek, j);
    
    if(i < koniec)
        szybkiSortowanie(i, koniec);



}


template<class T, int ilosc>
void Szybkie<T, ilosc>::wyswietlTablice()
{
    for(int i = 0; i < ilosc ; i++)
   {
       cout<<tablica[i]<<"  ";

   }
}



template<class T, int ilosc>
void Szybkie<T, ilosc>::wypelnijLosowymiLiczbami ()
{
   
   srand(time(NULL));
   for(int i = 0; i < ilosc ; i++)
   {
       tablica[i] = rand() % 100;
   }
   
   
}
