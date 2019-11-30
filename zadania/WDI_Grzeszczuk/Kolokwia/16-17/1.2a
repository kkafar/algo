/*
Zadanie 2b Kolos 2016/17
2. Proszę napisać program, który wypełnia tablicę int tab[MAX] liczbami pseudolosowymi
z zakresu [1 .. 1000], a następnie wyznacza i wypisuje sumę 10 największych elementów
z tablicy.
Uwagi:
- tablica tab zajmuje ponad połowę dostępnej pamięci na dane i nie może ulec zmianie (1)

szczerze mówiąc nie podoba mi się to rozwiązanie… (przepisane od Wojciecha Geislera z git.iiet - repo wdi)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <time.h>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 20;

void printTab(int T[], int N)
{
    REP(i, N)
    {
        cout << T[i] << " ";
    }
    cout << "\n";
}

int main()
{
    srand(time(NULL));

    // mamy tablicę z pseudolosowymi N-elementami
    int T[N];
    REP(i, N)
        T[i] = rand() % 1000 + 1;

    // robimy sobie drugą tablicę, na 10 najwięszych elem.
    int najwEl[10];
    REP(i, 10) 
        najwEl[i] = 0;

    // posortować nie możemy bo: (1)
    REP(i, N)
    {
        if (T[i] > najwEl[0])
        {
            // ten który jest obecnie najmniejszy sposród największych z tej tablicy oczywiście odpadnie
            najwEl[0] = T[i];
            // no i jeszcze potrzebujemy go umieścić na odpowiedniej pozycji
            for (int j = 1; j < 10 and najwEl[j] < T[i]; ++j)
            {
                najwEl[j - 1] = najwEl[j];
                najwEl[j] = T[i];
            }
        }
    }

    printTab(T, N);
    printTab(najwEl, 10); 
    
    return 0;
}
