/*
    ZESTAW 3
    ZADANIE 19

    Są fajne tricki: okres jest skończony dla 2 i 5 w rozkładzie, dla innych czynników nie
    czy coś takiego, ponoć jest na internecie


    Napisać funkcję, do której przekazujemy licznik i mianownik ułamka.
    Funkcja powinna wypisać wartość ułamka jako rozwinięcie dziesietne
    uwzględniające okres, np. 1/3 = 0.(3), 1/6 = 0.1(6) itd. 
*/


/* 
    Rozwiązanie gościa przy tablicy, z wszystkiego co wiedze to nie działa :D
*/
#include <iostream>
using namespace std;


const int MAX = 1000;

void okres(int a, int b)
{
    int rozw[MAX];
    bool wyjdz = false;
    int mod[MAX], zakres = 0, j = 0, i = 0;
    for (i = 0; a > 0 && j != i; ++i)
    {
        rozw[i] = (a * 10) / b; 
        mod[i] = a * 10;
        a = (a * 10) % b;
        zakres++;
        for (j = 0; j < i; j++)
        {
            if (mod[j] == mod[i])
            {
                wyjdz = true;
                break;
            }
        }

        if (wyjdz)
            break;
    }

    if (a == 0)
    {
        cout << "0.";
        for (int k = 0; k < i; ++k)
            cout << rozw[k];
    }

    else
    {
        cout << "0.";
        for (int k = 0; k < j; ++k)
        {
            cout << rozw[k];
        }
        cout << "(";
        for (int k = j; k < i; ++k)
            cout << rozw[k];
        cout << ")";
    }
}

int main()
{

    okres(9, 11);
    return 0;
}
