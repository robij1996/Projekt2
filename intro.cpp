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


template <class T>
void zmiana (T tablica[], int i, int j)
{
  T temp;

  temp = tablica[i];
  tablica[i] = tablica[j];
  tablica[j] = temp;

}


template <class T>
void kopiec (T tablica[], int i, int poczatek)
{
  int j;
  while (i <= poczatek / 2)
  {
    j = 2 * i;


    if (j + 1 <= poczatek && tablica[j + 1] > tablica[j])
      j= j + 1;

    if (tablica[i] < tablica[j])
      zmiana(tablica, i, j);

    else break;

    i = j;
  }
}

template <class T>
void kopcowanie (T tablica[], int poczatek)
{
  int i;


  for (i = poczatek / 2; i > 0; --i)
    kopiec(tablica - 1, i, poczatek);

  for (i = poczatek - 1; i > 0; --i)
  {
    zmiana(tablica, 0, i);
    kopiec(tablica-1, 1, i);
  }

}
 




template <class T>
void wstawianie (T tablica[], int poczatek)
{
  int i, j;
  T temp;


  for (i = 1; i < poczatek; ++i)
  {
    temp = tablica[i];


    for (j = i; j > 0 && temp < tablica[j-1]; --j)
        tablica[j] = tablica[j-1];

    tablica[j] = temp;

  }
}




template <class T>
void mediana (T tablica[], int &poczatek, int &koniec)
{
  if (tablica[++poczatek-1]>tablica[--koniec])
    zmiana(tablica,poczatek-1,koniec);

  if (tablica[poczatek-1]>tablica[koniec/2])
    zmiana(tablica,poczatek-1,koniec/2);

  if (tablica[koniec/2]>tablica[koniec])
    zmiana(tablica,koniec/2,koniec);

  zmiana(tablica,koniec/2,koniec-1);
}


template <class T>
int podzial (T tablica[], int poczatek, int koniec)
{
  int i, j;
  if (koniec >= 3)
    mediana(tablica, poczatek, koniec);
  for (i = poczatek, j = koniec - 2; ; )
  {


    for ( ; tablica[i] < tablica[koniec - 1]; ++i);

    for ( ; j >= poczatek && tablica[j] > tablica[koniec - 1]; --j);

        if (i < j)
             zmiana(tablica, i++, j--);
        else break;
  }

  zmiana(tablica, i, koniec - 1);

  return i;

}
 


template <class T>
void sortowanieIntro (T tablica[], int wielkosc, int limit)
{
  int i;
  
  if (limit <= 0)
  {
    kopcowanie(tablica, wielkosc);
    return;
  }

  i=podzial(tablica, 0, wielkosc);

  if (i > 9)
    sortowanieIntro(tablica, i, limit - 1);

  if (wielkosc - 1 - i > 9)
    sortowanieIntro(tablica + i + 1, wielkosc - 1 - i, limit - 1);
}



template <class T>
void introsort (T tablica[], int wielkosc)
{
  sortowanieIntro(tablica,wielkosc,(int)floor(2*log(wielkosc)));
  wstawianie(tablica,wielkosc);
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
            introsort<T>(tablica, wielkosc);
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
            introsort<T>(tablica, wielkosc);
            reverse( tablica, tablica + wielkosc );


            auto start = Clock::now();
            introsort<T>(tablica, wielkosc);
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