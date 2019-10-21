/* 
    ZESTAW 3 
    ZADANIE 3
    3.  Napisać program generujący i wypisujący liczby pierwsze mniejsze
        od N metodą Sita Eratostenesa
*/

#include <iostream>
using namespace std;

int main()
{
    int n; // zakres
    int factor; // czynnik z którego będziemy korzystać w pętli głównej algorytmu
    int * T = new int[n];

    cin >> n;
    
    // na starcie zerujemy tablicę T[]
    for (int i = 0; i < n; ++i) T[i] = 0; 

    // oczywiście T[0] = T[1] = 1, bo to nie są liczby pierwsze
    T[0] = T[1] = 1;

    // wykreślamy wszystkie wielokrotności kolejnych liczb naturalnych
    // (czyli do odpowiedniej komórki T[i] wpisujemy 1 - co oznacza że ta liczba na pewno nie jest pierwsza)
    for (int i = 2; i <= n/2; ++i)
    {
        // ustawiamy go na 2, żeby nie wykreślić T[i]
        factor = 2; 
        while ((i * factor) < n)
        {
            T[i * factor] = 1;
            ++factor;
        }
    }

    // wyświetlamy wszystkie i, dla których T[i] == 0 | powinny to być wszystkie liczby pierwsze od 2 do n (bez n);
    for (int i = 0; i < n; ++i)
        if (T[i] == 0)
            cout << i << " ";
    cout << "\n";

    // zwalniamy zarezerwowaną pamięć na tablicę T;
    delete[] T;
    return 0;
}
