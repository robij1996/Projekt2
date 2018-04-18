#include <iostream>
#include <cstdlib>
#include <cmath>
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
int podzial(T tablica[], int poczatek, int koniec)
{   
    int pivot = tablica[(koniec + poczatek) / 2];
    int pom;
    int i = poczatek;

    for (int j = poczatek; j < koniec; ++j)
    {
        if(tablica[j] <= pivot)
        {
            pom = tablica[j];
            tablica[j] = tablica[i];
            tablica[i] = pom;
            i++;
        }
    }
    tablica[koniec] = tablica[i];
    tablica[i] = pivot;

    return i;

}

/*
template<typename T>
void sortowanieSzybkie(T tablica[], int poczatek, int koniec)
{
    if(poczatek < koniec)
    {
        int q = podzial<T>(tablica, poczatek, koniec);
        sortowanieSzybkie<T>(tablica, poczatek, q -1 );
        sortowanieSzybkie<T>(tablica, q + 1, koniec );
    }

}*/


template<typename T>
void kopiec(T tablica[], int rozmiar, int id )
{
    int lewy = (id +1) * 2 - 1;
    int prawy = (id +1) * 2;
    int  najwiekszy = 0;

    if(lewy < rozmiar && tablica[lewy] > tablica[id])
        najwiekszy = prawy;
    else 
        najwiekszy = id;

    if(prawy < rozmiar && tablica[prawy] > tablica[najwiekszy])
        najwiekszy = prawy;

    
    if(najwiekszy != id)
    {
        int pom = tablica[id];
        tablica[id] = tablica[najwiekszy];
        tablica[najwiekszy] = pom;

        kopiec<T>(tablica, rozmiar, najwiekszy);
    }


}



template<typename T>
void kopcowanie(T tablica[], int wielkosc)
{
    int rozmiar = wielkosc;

    for(int p = (rozmiar -1 )/2; p >= 0; --p)
        kopiec(tablica, rozmiar, p);

    for(int i = wielkosc - 1; i > 0; --i)
    {
        int pom = tablica[i];
        tablica[i] = tablica[0];
        tablica[0] = pom; 

        --rozmiar;
        kopiec(tablica, rozmiar, 0);

    }

}

template<typename T>
void sortowanieIntro(T tablica[], int wielkosc, int max  )
{
    

    if(max <= 0)
    {
        kopcowanie<T>(tablica, wielkosc);
        return;
    }
    int i = podzial<T>(tablica, 0, wielkosc);

    if(i > 9)
        sortowanieIntro<T>(tablica, i, max - 1);
    if(wielkosc - 1 - i > 9)
        sortowanieIntro(tablica, wielkosc - 1 - i, max - 1);

}


template<typename T>
void introsort(T tablica[], int wielkosc)
{
    sortowanieIntro<T>(tablica, wielkosc, (int)(2*log(wielkosc) ) );
 
}



template<typename T>
void wypelnienieTablicy(T tab[], int wielkosc, double posortowane)
{
    double iloscPos = (double)wielkosc*posortowane;
    wypelnijTablice<T>(tab, iloscPos);
    introsort<T>(tab, wielkosc);
    wypelnijTablice<T>(tab, wielkosc - iloscPos + 1);

}

template<typename T>
void badanieIntroSortowania(int wielkosc, double posortowane)
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
        introsort<T>(tablica, wielkosc);
        auto stop = Clock::now();

        czas += (chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());


        
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
            introsort<T>(tablica, wielkosc);
            auto stop = Clock::now();

            czas += (chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());


            
        }
        cout<<"Średnia czasu dla tablicy "<<wielkosc<<" nie posortowanej wynosi: "<<czas/100000000<<"ms"<<endl;
        czas=0;
    }


    //tablica odwrotnie posortowana 
    if(posortowane == -1)
    {
        for(int i = 0; i<100; i++)
        {
            T tablica[wielkosc];

            introsort<T>(tablica, wielkosc);
            reverse( tablica, tablica + wielkosc );


            auto start = Clock::now();
            introsort<T>(tablica, wielkosc);
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



    badanieIntroSortowania<int>(rozmiar, -1);
    badanieIntroSortowania<int>(rozmiar, 0);
    badanieIntroSortowania<int>(rozmiar, 0.25);
    badanieIntroSortowania<int>(rozmiar, 0.5);
    badanieIntroSortowania<int>(rozmiar, 0.75);
    badanieIntroSortowania<int>(rozmiar, 0.95);
    badanieIntroSortowania<int>(rozmiar, 0.99);
    badanieIntroSortowania<int>(rozmiar, 0.997);




}








int main()
{
    eksperyment<int>(10000);
    eksperyment<int>(50000);
    eksperyment<int>(100000);
    eksperyment<int>(500000);
    eksperyment<int>(1000000);

 
 
    
    return 0;
}