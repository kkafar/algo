/*
    * ZADANIE 5
    * ZESTAW 5
Proszę napisać funkcję, która zwraca wartość true jeżeli zborze istnieją 4 punkty
wyznaczające kwadrat o bokach równoległych do osi układu współrzędnych, a wewnątrz tego
kwadratu nie ma żadnych innych punktów. Do funkcji należy przekazać strukturę opisującą
położenie punktów. 
*/

#include <iostream>
#include <iomanip>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)

const int size = 100;

int abs(int a)
{
    return ((a >= 0) ? (a) : (-a));
}
int min(int a, int b)
{
    return ((a <= b) ? (a) : (b));
}

struct punkt
{
    // x, y należą do {0, ..., 31}
    int x, y;
};

struct dane
{
    punkt T[size];
    int n;
};

// zakładamy że współrzędne punktów są danel
bool zad5(dane d)
{
    // wiemy że x, y należą do zbioru ograniczonego lewo i prawo stronnie
    // zatem iterujemy sobie po wszystkich możliwych wartościach i jeżeli jakaś występuje, 
    // to wpisujemy do mapy

    // najpierw tworzymy i zerujemy mapę 
    int mapa[32][32];
    FORU(i, 0, 31)
    {
        FORU(j, 0, 31)
            mapa[i][j] = -1;
    }
    // w mapa[i][j] trzymam -1 jeżeli nie ma punktu o wsp. (i, j)
    // lub indeks tego punktu z tablicy d.T[].
    FORU(i, 0, d.n - 1)
    {
        mapa[d.T[i].x][d.T[i].y] = i;
    }

    /*
        a teraz pałowanie:
        1. Z każdego punktu sprawdzamy wszystkie możliwe kwadraty
        tzn. bieżący punkt traktujemy jako lewy dolny róg i sprawdzamy wszystkie możliwe boki 
        kwadratów, aż nie wyjdziemy poza tablicę.  
        2. jeżeli uda nam się znaeźć kwadrat, to puszaczamy podwójną pętlę lecącą przez całe jego wnętrze
        i sprawdzamy czy jakiś punkt jest w środku: 
            - jeżeli nie: zwracamy true. Koniec zadania.
            - jeżeli tak: kontynuujemy dla kolejnej długości boku
        3. jeżeli przejechaliśmy przez wszystkie punkty i nie zwróciliśmy true, to oczywiście znaczy że nie ma kwadratu
        spełniającego warunki zadania ==> zwracamy false

        nie bawimy się w żadną estetykę. 
    */
    FORU(i, 0, 31)
    {
        FORU(j, 0, 31)
        {
            // jeżeli jest tu jakiś punkt to sprawdzamy wszystkie kwadraty dla niego 
            if (mapa[i][j] != -1)
            {
                FORU(dl, 1, min(abs(31 - i), abs(31 - j)))
                {
                    if (mapa[i + dl][j] != -1 && mapa[i][j + dl] != -1 && mapa[i + dl][j + dl] != -1)
                    {
                        // to oznacza, że mamy kwadrat, sprawdzamy teraz czy coś jest w środku 
                        FORU(m, i, i + dl)
                        {
                            FORU(n, j, j + dl)
                            {
                                if (mapa[m][n] != -1)
                                    break;
                                // jesznie nie koniec, ale wiemy jaki jest pomysł, a nie ma czasu. 
                            }
                        }
                    }
                }
            }
        }
    }
    // jeżeli nie udało nam się znaleźć: 
    return false;

}


int main()
{

    return 0;
}
