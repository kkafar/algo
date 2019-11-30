/*
ZESTAW 7 
ZADANIE 35
35. Dana jest tablica int t[N] zawierająca liczby naturalne. Proszę napisać funkcję,
która odpowiada na pytanie, czy spośród (niekoniecznie wszystkich) elementów
tablicy można utworzyć dwa podzbiory o jednakowej sumie elementów, tak aby suma
mocy obu podzbiorów wynosiła k. Do funkcji należy przekazać wyłącznie tablicę t
oraz liczbę naturalną k, funkcja powinna zwrócić wartość typu bool.

// ZAŁOŻENIE:
chodzi o zbiory rozłączne, niepuste (w taki sposób interpretuję treść)
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 6;

// A, B - sumy elementów w odpowiednich zbiorach
// mA, mB - moce odpowiednich zbiorów
bool func(int T[N], int k, int A = 0, int B = 0, int mA = 0, int mB = 0, int idx = 0)
{
    if (mA != 0 and mB != 0)
    {
        if (mA + mB == k and A == B)
            return true;
    }

    if (idx == N)
        return false;

    else
    {
        if (func(T, k, A + T[idx], B, mA + 1, mB, idx + 1)) return true;
        if (func(T, k, A, B + T[idx], mA, mB + 1, idx + 1)) return true;
        if (func(T, k, A, B, mA, mB, idx + 1))              return true;
    }
    return false;
}

int main()
{
    int T[N] = {1, 2, 3, 4, 5, 6};

    cout << func(T, 4) << "\n";
    //cout << isPrime(75123) << "\n";
    //cout << rev(32157) << "\n";
    return 0;
}
