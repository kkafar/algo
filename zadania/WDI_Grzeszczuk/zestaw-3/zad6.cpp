/*
    ZADANIE 6
    ZESTAW 3
    Proszę napisać program, który wczytuje wprowadzany z klawiatury
ciąg liczb naturalnych zakończonych zerem stanowiącym wyłącznie
znacznik końca danych. Program powinien wypisać 10 co do
wielkości wartość, jaka wystąpiła w ciągu. Można założyć, że w
ciągu znajduje się wystarczająca liczba elementów.


W TYM PODEJŚCIU NIE BIORĘ POD UWAGĘ POWTARZANIA SIĘ WARTOŚĆI 
Jeżeli coś się powtarza to po prostu jest pwisywane do tablicy, traktujemy 
to jako 10 największy element mulitizbioru a nie zbioru 
*/

#include <iostream>
#include <iomanip>
using namespace std;

// na siłę przyjmujemy wartość minimalną 
const int MINF(-10000000);
const int N(10);

int main()
{
    // tablica z 10 obecnie znanymi największymi wartościami
    // na starcie uzupełniamy ją wartościami MINF
    int T[N], liczba, iter;

    for (int i = 0; i < N; ++i) T[i] = MINF;

    // obsługujemy wejśie 
    while(1) 
    {
        // pobieramy pierwszą/kolejną liczbę z wejścia
        cin >> liczba;
        // jeżeli dostaejmy znacznik końca danych to przerywamy
        if (liczba == 0)
            break;

        // zerujemy iterator
        iter = 0; 
        // jedziemy po tablicy od lewej, w T[0] przechowujemy największą do tej
        // pory znalezioną wartość. Jeżeli napotkamy w tablicy liczbę która jest mniejsza
        // od liczby podanej na wejście, to: 
        /*
            1. Zapamiętujemy liczbę na pozycji i. 
            2. do T[i] wpisujemy naszą liczbę z wejścia. 
            3. Przesuwamy wszystkie wartości począwszy od starej wartości z T[i] w prawo o jeden indeks
            T[N - 1] wypada poza tablicę.  
        */ 
        // szukamy indeksu dla którego zachodzi liczba > T[iter]
        while (iter < N && T[iter] >= liczba)
            ++iter;

        // przesuwamy wszystko w prawo
        for (int i = N - 1; i >= iter + 1; --i)
            T[i] = T[i - 1];
        
        T[iter] = liczba;
    }

    cout << T[N - 1] << "\n";


    return 0;
}
