/*
    Probabilistyczny test pierwszości liczby Millera-Rabina. 
    
    linki do opracowań: 
    1. https://pl.wikipedia.org/wiki/Test_Millera-Rabina
    2. https://eduinf.waw.pl/inf/alg/001_search/0019.php

    Ważne są także takie informacje:
    dla n < 4 759 123 141 wystarczy sprawdzić a = 2, 7, 61
    dla n < 341 550 071 728 321 wystarczy sprawdzić a = 2, 3, 5, 7, 11, 13, 17
*/

#include <iostream>
using namespace std;

// do algorytmu Millera-Rabina potrzebujemy móc szybko obliczać a^p mod q
// zatem korzystamy z algortymu szybkiego potęgowania modularnego
int powerMod(const int a, int p, const int mod)
{
    int remainder = a, result = 1;

    while (p)
    {
        if (p & 1) result = (remainder * result) % mod;

        remainder = (remainder * remainder) % mod;
        p >>= 1;
    } 

    return result;
}

// zakładamy że wejście do naszego programu nie przekracza zakresu zmiennej int (do 2,147,483,647)
// zatem są to podstawy przy których będziemy sprawdzać pierwszość każdej z liczb
const int bases[3] = {2, 7, 61};

bool isPrime(const int p) 
{
    // potrzebujemy najpierw znaleźć ile dwójek znajduje się w rozkładzie liczby p-1, 
    // bo chcemy p przedstawić w postaci p = 2^s × d + 1
    int s = 0, d = p - 1;
    // dopóki w rozkładzie d jest jakaś dwójka 
    while (!(d & 1)) 
    {
        ++s;
        d >>= 1;
    }
    // a^(2^j * d) mod p == x
    int x;
    for (int i = 0; i < 3; ++i)
    {
        // pamiętajmy, że podstawę przy której sprawdzamy pierwszość wybieramy
        // z przedziału {1, … , p - 1}, zatem musimy sprawdzić czy nasze podstawy spełniają ten warunek. 
        if (bases[i] < p)
        {
            // zaczynamy od x = a^d mod p
            x = powerMod(bases[i], d, p);

            if (x == 1 || x == (p - 1)) continue; 

            int j = 1; 

            while ((j < s) && (x != (p - 1)))
            {
                x = (x * x) % p; 
                if (x == 1) return false;
                ++j;
            }
            if (x != p - 1) return false;
        } 
    }
    return true;
}

int main()
{
    int p, z;

    cin >> z; 

    for (int i = 0; i < z; ++i)
    {
        cin >> p;

        // special case dla p == 2, bo test Millera Rabina zakłada p > 2
        if (p == 2)              cout << "Pierwsza\n";
        
        // jeżeli p jest parzyste, mniejsze od 2 od razu zwracamy false
        else if (!(p & 1) || p < 2)   cout << "Zlozona\n"; // czy 1 jest liczbą złożoną? Tak samo 0? No ale piszmy dla uproszczenia że złożona

        // dla nieparzystego p > 2
        else cout << ((isPrime(p) == true) ? "Pierwsza\n" : "Zlozona\n");

    }
    return 0;
}
