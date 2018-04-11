#ifndef SCAL_HH
#define SCAL_HH

const int N = 10;
const int M = 10;

class Scalanie 
{

    public:

    int tab_pom[N] ;
    int *tablica = new int [N];

    void wyswietlTablice();
    void wypelnijLosowymiLiczbami ();

    //Scalanie();

    void scalanie(int poczatek, int srodek, int koniec);
    void sortowanieScalanie(int poczatek, int koniec);



};



#endif