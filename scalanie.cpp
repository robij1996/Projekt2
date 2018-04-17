#include<iostream>
#include<cstdlib>
#include<cmath>
#include <ctime>
#include <chrono>
#include <algorithm>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;



template<typename T>
void wyswietlTablice(T tab[],int wielkosc)
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
void wypelnijTablice(T tab[], int wielkosc)
{
    srand(time(NULL));
    for(int i = 0; i < wielkosc ; i++)
    {
       tab[i] = rand() % 10000;
    }


    
}

template<typename T>
void scal(T tablica[], int poczatek, int srodek, int koniec)
{
    int i;
    int j;
    int k;
    T tab_pom[koniec];
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






template<typename T>
void sortowanieScalcanie(T tab[], int poczatek, int koniec)
{
    if(koniec <= poczatek)
        return;

    int srodek = (poczatek + koniec)/2;

    sortowanieScalcanie<T>(tab, poczatek, srodek);
    sortowanieScalcanie<T>(tab, srodek + 1, koniec);

    scal(tab, poczatek, srodek, koniec);
}

template<typename T>
void wypelnienieTablicy(T tab[], int wielkosc, double posortowane)
{
    double iloscPos = (double)wielkosc*posortowane;
    wypelnijTablice<T>(tab, iloscPos);
    sortowanieScalcanie<T>(tab, 0, wielkosc - 1);
    wypelnijTablice<T>(tab, wielkosc - iloscPos + 1);



}




template<typename T>
void badanieSortowanieScalanie(int wielkosc, double posortowane)
{
    double czas;

    if(posortowane > 0)
    {
        for(int i = 0; i<100; i++)
        {
        T tablica[wielkosc];

        wypelnienieTablicy(tablica, wielkosc, posortowane);

        auto start = Clock::now();
        sortowanieScalcanie<T>(tablica, 0, wielkosc - 1);
        auto stop = Clock::now();

        czas += (std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());


        
        }
        cout<<"Średnia czasu dla tablicy "<<wielkosc<<"  posortowanej "<<posortowane<< " wynosi: "<<czas/100000000<<"ms"<<endl;
        czas=0;
    }


    //tablica bez wstepnego sortowania 
    if(posortowane == 0)
    {
        for(int i = 0; i<100; i++)
        {
            T tablica[wielkosc];

            wypelnijTablice<T>(tablica, wielkosc);

            auto start = Clock::now();
            sortowanieScalcanie<T>(tablica, 0, wielkosc - 1);
            auto stop = Clock::now();

            czas += (std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());


            
        }
        cout<<"Średnia czasu dla tablicy "<<wielkosc<<" nie posortowanej wynosi: "<<czas/100000000<<"ms"<<endl;
        czas=0;
    }


    if(posortowane == -1)
    {
        for(int i = 0; i<100; i++)
        {
            T tablica[wielkosc];

            sortowanieScalcanie<T>(tablica, 0, wielkosc - 1);
            reverse( tablica, tablica + wielkosc );


            auto start = Clock::now();
            sortowanieScalcanie<T>(tablica, 0, wielkosc - 1);
            auto stop = Clock::now();

            czas += (std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());


            
        }
            cout<<"Średnia czasu dla tablicy "<<wielkosc<<" odwrtonie posortowanej wynosi: "<<czas/100000000<<"ms"<<endl;
            czas=0;

    }
}




template<typename T>
void eksperyment(int rozmiar)
{
    badanieSortowanieScalanie<int>(rozmiar, -1);
    badanieSortowanieScalanie<int>(rozmiar, 0);
    badanieSortowanieScalanie<int>(rozmiar, 0.25);
    badanieSortowanieScalanie<int>(rozmiar, 0.5);
    badanieSortowanieScalanie<int>(rozmiar, 0.75);
    badanieSortowanieScalanie<int>(rozmiar, 0.95);
    badanieSortowanieScalanie<int>(rozmiar, 0.99);
    badanieSortowanieScalanie<int>(rozmiar, 0.997);


}


int main()
{

   eksperyment<int>(100);

 
 
    
    return 0;
}


