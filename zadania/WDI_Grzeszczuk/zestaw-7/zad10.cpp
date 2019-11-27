/*
    ZESTAW 7
    ZADANIE 10 (D)
10. Dana jest tablica int t[N]. Proszę napisać program zliczający liczbę “enek” o
określonym iloczynie. 


Przydałoby się trochę więcej założeń w treści :D
Zakładamy: 
1. Nie bierzemy liczby 1 do rozkładu
2. Liczby w tablicy są różne (jeżeli nie są, to kilkukrotnie może być zliczony ten sam rozkład)
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 9;
int T[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

void nki(const int T[N], int idx, int n, int prod, int & count)
{
    // jeżeli n == 0, to znaczy że wzieliśmy n liczb do naszego rozkładu, więc więcej już nie chcemy
    // a skoro mamy n liczb w rozkładzie (i ich iloczyn jest oczywiście równy szukanemu) to ++count
    if (n == 0) {
        ++count;
        return;
    }
    // jeżeli wychodzimy poza tablicę to już nie za bardzo coś uda sie znaleźć 
    if (idx == N) {
        return;
    }

    // jeżeli nie zwróciliśmy w żadnym poprzednim przypadku 
    // jeżeli liczba na którą aktualnie patrzymy może się znaleźć w rozkładzie, to możemy ją zabrać
    if (prod % T[idx] == 0 && T[idx] != 1) {            // jedynek nie bierzemy do rozkładu, dla jednoznaczności 
        nki(T, idx + 1, n - 1, prod / T[idx], count);
    }
    // przypadek gdy jej nie zabieramy
    nki(T, idx + 1, n, prod, count);

    
}

int main()
{
    //int t[N] = {1, 7, 3, 5, 11, 2};
    int counter = 0;
    nki(T, 0, 2, 6, counter);
    cout << counter << "\n";


    return 0;
}
