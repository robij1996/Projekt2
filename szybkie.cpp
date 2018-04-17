#include<iostream>
#include<cstdlib>
#include<cmath>
#include <ctime>
#include <chrono>
#include <algorithm>

typedef std::chrono::high_resolution_clock Clock;

using namespace std;


template<typename T>
void wyswietlTablice(T tab[] ,int wielkosc)
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
void szybkiSortowanie(T tablica[], int poczatek , int koniec)
{
    if(koniec <= poczatek) return;

    int i, j, pivot; 
    i = (poczatek + koniec) / 2 ;
    pivot = tablica[i];

    for(j = i = poczatek; i < koniec; i++)
    {
        swap(tablica[i], tablica[j]);
        j++;
    }
    
    tablica[koniec] = tablica[j];
    tablica[j] = pivot;

    if(poczatek < j - 1)
    szybkiSortowanie<T>(tablica, poczatek, j - 1);
    if(j + 1 < koniec)
    szybkiSortowanie<T>(tablica, j +1, koniec);




}


template<typename T>
void wypelnienieTablicy(T tab[], int wielkosc, double posortowane)
{
    double iloscPos = (double)wielkosc*posortowane;
    wypelnijTablice<T>(tab, iloscPos);
    szybkiSortowanie<T>(tab, 0, wielkosc);
    wypelnijTablice<T>(tab, wielkosc - iloscPos + 1);



}







template<typename T>
void badanieSzybkiegoSortowania(int wielkosc, double posortowane)
{
    double czas;

    // tablica z wstepnym sortowaniem 
    if(posortowane > 0)
    {
        for(int i = 0; i<100; i++)
        {
        T tablica[wielkosc];

        wypelnienieTablicy(tablica, wielkosc, posortowane);

        auto start = Clock::now();
        szybkiSortowanie<T>(tablica, 0, wielkosc);
        auto stop = Clock::now();

        czas += (chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());


        
        }
        cout<<"Średnia czasu dla tablicy "<<wielkosc<<"  posortowanej "<<posortowane<< " wynosi: "<<czas/100000000<<"ms"<<endl;
        czas=0;
    }


    //tablica bez wstepnego sortowania 
    if(posortowane == 0)
    {
       /* for(int i = 0; i<1; i++)
        {*/
            T tablica[wielkosc];

            wypelnijTablice<T>(tablica, wielkosc);

            auto start = Clock::now();
            szybkiSortowanie<T>(tablica, 0, wielkosc);
            auto stop = Clock::now();

            czas += (chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());


            
        //}
        cout<<"Średnia czasu dla tablicy "<<wielkosc<<" nie posortowanej wynosi: "<<czas/1000000<<"ms"<<endl;
        czas=0;
    }


    //tablica odwrotnie posortowana 
    if(posortowane == -1)
    {
        for(int i = 0; i<100; i++)
        {
            T tablica[wielkosc];

            szybkiSortowanie<T>(tablica, 0, wielkosc);
            reverse( tablica, tablica + wielkosc );


            auto start = Clock::now();
            szybkiSortowanie<T>(tablica, 0, wielkosc);
            auto stop = Clock::now();

            czas += (chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());


            
        }
            cout<<"Średnia czasu dla tablicy "<<wielkosc<<" odwrtonie posortowanej wynosi: "<<czas/100000000<<"ms"<<endl;
            czas=0;

    }

}

    //odnosie sortowan 
    // wartosc -1 odwrotnie posortowana 
    // wartosc 0 brak wstepnego sortowania 
    // < 0 posortowana w jakims procencie 
template<typename T>
void eksperyment (int rozmiar)
{


    //badanieSzybkiegoSortowania<int>(rozmiar, -1);
    badanieSzybkiegoSortowania<int>(rozmiar, 0);
   /* badanieSzybkiegoSortowania<int>(rozmiar, 0.25);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.5);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.75);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.95);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.99);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.997);*/



}








int main()
{

   eksperyment<int>(100);

 
 
    
    return 0;
}