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
void sprawdzKolejnosc(T tablica[], int wielkosc)
{

    for(int i = 1; i < wielkosc ; i++)
    {
       if(tablica[i-1] > tablica[i])
       {
            cout<<"Jest zle posortowana"<<endl;
            break;
       }

    }


}





template<typename T>
void szybkiSortowanie(T tablica[], int poczatek , int koniec)
{
    
    int i = poczatek, j = koniec;
    int tmp;

    // w celu badania wplywu wyboru pivota na rezultat sortowania
    //int pivot = tablica[koniec-1];
    int pivot = tablica[(poczatek+koniec)/2];            

      while (i <= j) 
      {
            while (tablica[i] < pivot)
                  i++;

            while (tablica[j] > pivot)
                  j--;

            if (i <= j) 
            {
                  tmp = tablica[i];
                  tablica[i] = tablica[j];
                  tablica[j] = tmp;
                  i++;
                  j--;
            }

      };

      if (poczatek < j)
            szybkiSortowanie<T>(tablica, poczatek, j);
      if (i < koniec)
            szybkiSortowanie<T>(tablica, i, koniec);




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

        sprawdzKolejnosc<T>(tablica, wielkosc);
        
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
            szybkiSortowanie<T>(tablica, 0, wielkosc);
            auto stop = Clock::now();

            czas += (chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());

            sprawdzKolejnosc<T>(tablica, wielkosc);
            
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
            wypelnijTablice<T>(tablica, wielkosc);
            szybkiSortowanie<T>(tablica, 0, wielkosc);
            reverse( tablica, tablica + wielkosc );

            auto start = Clock::now();
            szybkiSortowanie<T>(tablica, 0, wielkosc);
            auto stop = Clock::now();
            czas += (chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());

            sprawdzKolejnosc<T>(tablica, wielkosc);
            
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

    badanieSzybkiegoSortowania<int>(rozmiar, -1);
    badanieSzybkiegoSortowania<int>(rozmiar, 0);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.25);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.5);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.75);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.95);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.99);
    badanieSzybkiegoSortowania<int>(rozmiar, 0.997);




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