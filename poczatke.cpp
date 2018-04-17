#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;


template<typename T>
void wyswietlTablice(T* tab,int wielkosc)
{
    for(int i = 0; i < wielkosc ; i++)
    {
        cout<<tab[i]<<"  ";
        if(i!=0 && i%15==0)
        cout<<endl;

    }
    cout<<endl;
}

template<typename T>
void wypelnijTablice(T *tab, int wielkosc)
{
    srand(time(NULL));
    for(int i = 0; i < wielkosc ; i++)
    {
       tab[i] = rand() % 10000;
    }


    
}

template<typename T>
int dzielenieTablicy(T *tablica, int poczatek, int koniec)
{
    int x = tablica[koniec];
    int tab_pom;
    int i = poczatek;

    for(int j = poczatek ; j < koniec; ++j)
    {
        if(tablica[j] <= x)
        {
            tab_pom = tablica[j];
            tablica[j] = tablica[i];
            tablica[i] = tab_pom;
            i++;
        }
    }

    tablica[koniec] = tablica[i];
    tablica[i] = x;
    return i;

}


template<typename T>
void szybkiSortowanie(T *tablica, int poczatek , int koniec)
{
   if(poczatek < koniec)
   {
       int pomocnicza = dzielenieTablicy<T>(tablica, poczatek, koniec);
       szybkiSortowanie<T>(tablica, poczatek, pomocnicza - 1);
       szybkiSortowanie<T>(tablica, pomocnicza + 1, koniec);
   }


}

template<typename T>
void scalanie(T *tablica, int poczatek, int srodek, int koniec)
{
    int i;
    int j;
    int k;
    T *tab_pom = new T [koniec];
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


    delete [] tab_pom;
}



template<typename T>
void sortowanieScalanie(T *tablica,int poczatek, int koniec)
{
    int srodek;

    if(poczatek < koniec)
    {
        srodek = (poczatek + koniec)/2;
        sortowanieScalanie<T>(tablica, poczatek, srodek);
        sortowanieScalanie<T>(tablica, srodek + 1, koniec);
        scalanie<T>(tablica, poczatek, srodek, koniec);

    }


}




template<typename T>
void sortowanieIntro(T *tablica, int wielk)
{
    int wartoscTab = dzielenieTablicy<T>(tablica, 0, wielk);


     if(wartoscTab > ( 2 * log(wielk) ) )
    {
        sortowanieScalanie<T>(tablica, 0, wielk);
        cout<<"sjasdf"<<endl;
    }
    else 
    {
        szybkiSortowanie<T>(tablica, 0, wielk);
        cout<<"sjf"<<endl;
    }

}


template<typename T, int wielkosc>
void badanieSzybkiegoSortowania()
{
    T *tablica = new T [wielkosc];

    wypelnijTablice<T>(tablica, wielkosc);
    wyswietlTablice<T>(tablica, wielkosc);
    szybkiSortowanie<T>(tablica, 0, wielkosc);
    wyswietlTablice<T>(tablica, wielkosc);
    delete [] tablica;
}

template<typename T, int wielkosc>
void badanieSortowanieScalanie()
{
    T *tablica = new T [wielkosc];
    wypelnijTablice<T>(tablica, wielkosc);
    wyswietlTablice<T>(tablica, wielkosc);
    sortowanieScalanie<T>(tablica, 0, wielkosc);
    wyswietlTablice<T>(tablica, wielkosc);
    delete [] tablica;

    
}



template<typename T, int wielkosc>
void badanieIntrosortu()
{   
    T *tablica = new T [wielkosc];
    wypelnijTablice<T>(tablica, wielkosc);
    //wyswietlTablice<T>(tablica, wielkosc);
    sortowanieIntro<T>(tablica,  wielkosc);
    //wyswietlTablice<T>(tablica, wielkosc);
    delete [] tablica;

}



int main()
{
    
    //badanieSzybkiegoSortowania<int, 10>();
    //badanieSortowanieScalanie<int, 10>();
    badanieIntrosortu<int, 10>();
 
 
    
    return 0;
}