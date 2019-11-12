/*
    * ZADANIE 4
    * ZESTAW 5
Dana jest tablica ulamek t[100] zawierająca ciąg liczb wymiernych. Proszę napisać
funkcję, która policzy występujące w tablicy ciągi arytmetyczne (LA) i geometryczne (LG)
o długości większej niż 2. Funkcja powinna zwrócić wartość 1 gdy LA>LG, wartość -1 gdy
LA<LG oraz 0 gdy LA=LG.
*/

#include <iostream>
#include <iomanip>
#include "ulamek.h"
using namespace std;

const int size = 100;

int zad4(ulamek T[size])
{
    /*
        LA, LG - jak w zadaniu
        la - obecna długość ciągu arytmetycznego 
        lg - obecna długość ciągu geometrycznego 
    */
    int LA = 0, LG = 0, la = 0, lg = 0
    ulamek r, q;
    r = T[1] - T[0]; la = 1; 
    q = T[1] / T[0]; lg = 1;
    // sprawdzamy każdą kolejną parę
    for (int i = 2; i < size; ++i)
    {
        // sprawdzamy warunek ciągu arytmetycznego
        if (T[i] - T[i - 1] == r)
        {
            // jeżeli tak, to zwiększamy la;
            ++la;
        }
        else
        {
            if (la >= 3) ++LA;
            r = T[i] - T[i - 1];
            la = 1;
        }

        if ((T[i] / T[i - 1]) == q)
            ++lg;

        else
        {
            if (lg >= 3) ++LG;
            q = T[i] / T[i - 1]; 
            lg = 1;
        }
    }

    if (LA > LG)    return 1;
    if (LA < LG)    return -1;
    else            return 0;
}


int main()
{

    return 0;
}
