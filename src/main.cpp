#include<iostream>
#include<cstdlib>
#include"scalanie.hh"
#include"szybki.hh"
#include"kontener.hh"

using namespace std;





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