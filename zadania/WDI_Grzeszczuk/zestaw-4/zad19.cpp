/* 
    zadanie 19 zestaw 4
    Protip, traktować tablicę dwuwymiarową jako jedno wymiarową
*/

#include <iostream>
using namespace std;


/*
    Przeliczanie indeksów z liniowej na macierz:
    (M/MAX, M % MAX)

    idea jest taka, że sprawdzamy wszystkie pola na które możemy skoczyć skoczkiem w dół!!
    W góre sprawdzać już nie trzeba
    Kod w telefonie. 
    Zawsze sprawdzamy czy się mieścimy w tablicy dwuwymiarowej xD 
*/



const int MAX = 100;
int pairs(int T[MAX][MAX],int iloczyn)
{
    // nasza tablica liczb z zadania / aktualnie wyliczony iloczyn
    // 
    result = 0;
    //linearyzujemy tablicę T;

    // sprawdzmay wszystkie pary
    for (int i = 0; i < MAX * MAX; ++i)
    {
        for (int j = i + 1; j < MAX * MAX; ++j)
        {
            if (T[i/MAX][i%MAX] * T[j/MAX][j % MAX] == iloczyn) ++result;
        }
    }

    return result;
}

