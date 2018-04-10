#include<iostream>
#include<cstdlib>
#include"scalanie.hh"
#include"kontener.hh"

using namespace std;




Scalanie::Scalanie()
{
    srand(time(NULL));
   for(int i = 0; i < N ; i++)
   {
       tablica[i] = rand() % M;
   }


}


void Scalanie::scalanie(int poczatek, int srodek, int koniec)
{
    int i;
    int j;
    int k;

    for(i = poczatek; i <= koniec; i++)
        tab_pom[i] = tablica[i];

    i = poczatek;
    j = srodek+1;
    k = poczatek;

    while(i <= srodek && j <= koniec)
    {
        if(tab_pom[i] < tab_pom[j])
            tablica[k++] = tab_pom[i++];
        else
            tablica[k++] = tab_pom[j++];

    }

    while(i <= srodek)
        tablica[k++] = tab_pom[i++];


  


}

void Scalanie::sortowanieScalanie(int poczatek, int koniec)
{
    int srodek;

    if(poczatek < koniec)
    {
        srodek = (poczatek + koniec)/2;
        sortowanieScalanie(poczatek, srodek);
        sortowanieScalanie(srodek + 1, koniec);
        scalanie(poczatek, srodek, koniec);

    }


}
