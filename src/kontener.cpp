#include<iostream>
#include<cstdlib>
#include"kontener.hh"

using namespace std;


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