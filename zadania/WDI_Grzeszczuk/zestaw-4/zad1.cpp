/*
    ZESTAW 4
    ZADANIE 1
1. Dana jest tablica int t[MAX][MAX]. Proszę napisać funkcję wypełniającą tablicę
liczbami naturalnymi po spirali.

*/

#include <iostream>
#include <iomanip>
using namespace std;

#define FORU(i, b, e) for (int i = b; i <= e; ++i)
#define FORD(i, b, e) for (int i = b; i >= e; --i)

const int SIZE = 7;

void print_tab(int T[SIZE][SIZE])
{
    FORU(i, 0, SIZE -1)
    {
        FORU(j, 0, SIZE - 1)
        {
            cout << setw(4) << T[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

int main()
{
    int T[SIZE][SIZE], iter = 0, w1 = 0, w2 = SIZE-1, k1 = 0, k2 = SIZE-1;
    /*
        w1 - indeks górnego marginesu
        w2 - indeks dolnego marginesu
        k1 - indeks lewego marginesu
        k2 - indeks prawego marginesu
    */

    // zerujemy naszą tablicę, nie jest to konieczne
    FORU(i, 0, SIZE -1) 
        FORU(j, 0, SIZE -1)
            T[i][j] = 0;

    while (iter < SIZE * SIZE)
    {
        // powiększamy licznik iteracji
        //++iter;

        // pierwszy górny, nie zapisany wiersz
        FORU(i, k1, k2)
            T[w1][i] = iter++;

        // skoro przerobiliśmy najwyższy wiersz, to obniżamy górny margines
        ++w1;

        // teraz lecimy w dół prawym marginesem
        FORU(i, w1, w2)
            T[i][k2] = iter++;

        // prawy margines zrobiony, no to go zwężamy
        --k2;

        // teraz dolny margines
        FORD(i, k2, k1)
            T[w2][i] = iter++;

        // dolny margines wypełniony, no to go podwyższamy
        --w2;

        // jeszcze pozostało wyjechać w górę
        FORD(i, w2, w1)
            T[i][k1] = iter++;

        // no i zwężamy lewy margines
        ++k1;
    }

    print_tab(T);

    return 0;
}
