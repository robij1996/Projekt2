#ifndef KON_HH
#define KON_HH


const int N = 15; // rozmiar tablic 
const int M = 100; // zakres liczb losowanych 

class Kontener
{
    public:

    int *tablica = new int [N];

    void wyswietlTablice();
    void wypelnijLosowymiLiczbami ();

};



#endif