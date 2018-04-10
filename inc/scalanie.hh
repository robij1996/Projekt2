#ifndef SCAL_HH
#define SCAL_HH
#include"kontener.hh"

class Scalanie : public Kontener
{

    public:

    int tab_pom[N] ;

    Scalanie();

    void scalanie(int poczatek, int srodek, int koniec);
    void sortowanieScalanie(int poczatek, int koniec);



};



#endif