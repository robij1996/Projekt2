#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <cmath>
#include <chrono>
#include <algorithm>
typedef std::chrono::high_resolution_clock Clock;
using namespace std;

const int N = 1000000; // Liczebność zbioru.

int d[N];

// Procedura sortowania szybkiego
//-------------------------------

void Sortuj_szybko(int lewy, int prawy)
{
  int i,j,piwot;

  i = (lewy + prawy) / 2;
  piwot = d[i]; d[i] = d[prawy];
  for(j = i = lewy; i < prawy; i++)
  if(d[i] < piwot)
  {
    swap(d[i], d[j]);
    j++;
  }
  d[prawy] = d[j]; d[j] = piwot;
  if(lewy < j - 1)  Sortuj_szybko(lewy, j - 1);
  if(j + 1 < prawy) Sortuj_szybko(j + 1, prawy);
}

// Program główny
//---------------

int main()
{
  int i;

  srand((unsigned)time(NULL));

  cout << "   Sortowanie szybkie\n"
          "------------------------\n"
          " (C)2005 Jerzy Walaszek \n\n"
          "Przed sortowaniem:\n\n";

// Najpierw wypełniamy tablicę d[] liczbami pseudolosowymi
// a następnie wyświetlamy jej zawartość

  for(i = 0; i < N; i++) d[i] = rand() % 100;

double czas;
// Sortujemy
auto start = Clock::now();
  Sortuj_szybko(0,N - 1);
              
           
            auto stop = Clock::now();

            czas += (chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());
// Wyświetlamy wynik sortowania

  cout << "czas: "<<czas/1000000<<endl;

  return 0;
} 