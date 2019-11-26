/*
    ZESTAW 7
    ZADANIE 3
    7. Dana jest tablica int t[N]. Proszę napisać funkcję, która znajdzie niepusty,
najmniejszy (w sensie liczebności) podzbiór elementów tablicy, dla którego suma
elementów jest równa sumie indeksów tych elementów. Do funkcji należy przekazać
tablicę, funkcja powinna zwrócić sumę elementów znalezionego podzbioru. Na przykład
dla tablicy: [ 1, 7, 3, 5, 11, 2 ] rozwiązaniem jest liczba 10.

Uwagi: 
Nie jestem pewien (a raczej przychylam się do zdania że "nie") czy zawsze znajduje najmniejszy podzbiór
Do tego jeżeli na indeksie 0 stoi liczba 0 to też nie powinno zadziałać prawidłowo (czyli nie zwróci 0) (ale nie
sprawdzałem)
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int N = 6;
int MOC = 1000000; // załóżmy że inf
int T[N] = {1, 7, 3, 5, 11, 2};


int func(int t[N], int idx = 0, int sumaEl = 0, int sumaIdx = 0, int moc = 0)  // func(t, 0, 0, 0, 0)
{
    if ((sumaEl == sumaIdx) && sumaIdx != 0)
    {
        MOC = moc;
        return sumaEl;
    } 
    if (idx == N)
    {
        return -1;
    } 
    // jeżeli mam moc mojego zbioru mniejszą niż aktualne minimum (MOC) to jest sens się w ogóle dalej wywoływać
    if (moc < MOC)
    {
        // to mogę wziąć element, lub go nie wziąć 
        // nie biorę elementu: to wywołuję się: dla tej samej tablicy, na kolejnym elemencie, z tą samą sumą elementów w zbiorze,
        // z tą samą suma indeksów elementów w zbiorze, z tą samą mocą zbioru
        // Jeżeli to wywołanie zwróci mi coś innego niż -1, to znaczy że dla tak podjętej decyzji udało się znaleźć zbiór spełniający warunki zadania
        int niebiore = func(t, idx + 1, sumaEl, sumaIdx, moc);
        if (niebiore != -1)
        {
            return niebiore;
        }
        int biore = func(t, idx + 1, sumaEl + t[idx], sumaIdx + idx, moc + 1);
        if (biore != -1)
            {
                return biore;
            }
    }
    else 
    {
        return -1;
    }

}

int main()
{
    //int t[N] = {1, 7, 3, 5, 11, 2};

    cout << func(T, 0, 0) << "\n";
    return 0;
}
