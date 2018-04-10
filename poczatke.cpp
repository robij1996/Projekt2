#include<iostream>
#include<cstdlib>
#include <vector>
#include"szybki.hh"
using namespace std;

const int N = 15; // rozmiar tablic 
const int M = 100; // zakres liczb losowanych 


class Kontener
{
    public:

    int *tablica = new int [N];

    void wyswietlTablice();
    void wypelnijLosowymiLiczbami ();

};

class Szybkie : public Kontener 
{
    public:

    Szybkie();
  

    void szybkiSortowanie(int poczatek , int koniec);

};

class Scalanie : public Kontener
{

    public:

    int tab_pom[N] ;

    Scalanie();

    void scalanie(int poczatek, int srodek, int koniec);
    void sortowanieScalanie(int poczatek, int koniec);



};

class Intro : public Kontener
{

};



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








void Kontener::wyswietlTablice()
{
    for(int i = 0; i < N ; i++)
   {
       cout<<tablica[i]<<"  ";

   }
}




void Kontener::wypelnijLosowymiLiczbami ()
{
   
   srand(time(NULL));
   for(int i = 0; i < N ; i++)
   {
       tablica[i] = rand() % M;
   }
   
   
}





int main()
{

    Szybkie szTab;
    Scalanie sTab; 


    szTab.wyswietlTablice();
    cout<<endl;
    szTab.szybkiSortowanie(0, N - 1);
    szTab.wyswietlTablice();

    cout<<endl;
    cout<<endl;
    sTab.wypelnijLosowymiLiczbami();
    sTab.wyswietlTablice();
    cout<<endl;
    sTab.sortowanieScalanie(0, N-1 );
    sTab.wyswietlTablice();
  
    

 
    
    return 0;
}