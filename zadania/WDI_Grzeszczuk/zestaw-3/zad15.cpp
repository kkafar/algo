/*
ZESTAW 3, ZADANIE 15
15. Napisać program wyznaczający na drodze eksperymentu
prawdopodobieństwo tego, że w grupie N przypadkowo spotkanych
osób, co najmniej dwie urodziły się tego samego dnia roku.
Wyznaczyć wartości prawdopodobieństwa dla N z zakresu 20-40.
*/

#include <iostream>
#include <time.h>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 20;
const int ilosc_prob = 10000000;

int main()
{
    srand(time(NULL));
    int powt[365];

    double P = 0;
    double licznik = 0;

    REP(j, ilosc_prob)
    {
        REP(i, 365)     powt[i] = 0;
        REP(i, N)       powt[rand() % 365]++;
        REP(i, 365)
        {
            if (powt[i] >= 2)
            {
                ++licznik;
                break;
            }
        }
    }
    P = licznik / ilosc_prob;




    cout << P << "\n";
    return 0;
}
