#include<iostream>
#include<cstdlib>
#include"szybki.hh"
#include"kontener.hh"

using namespace std;





Szybkie::Szybkie()
{
    srand(time(NULL));
   for(int i = 0; i < N ; i++)
   {
       tablica[i] = rand() % M;
   }

}



void Szybkie::szybkiSortowanie(int poczatek , int koniec)
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

