/*
  ZESTAW 3
  ZADANIE 4
  4. Napisać program obliczający i wypisujący wartość N! dla N z
zakresu od 1 do 1000.
*/

#include <iostream>
using namespace std;

const int MAX_DIGIT = 3000;

int main()
{
    int n, factorial[MAX_DIGIT], overflow = 0;

    // zerujemy od razu tablicę przechowującą silnię
    for (int i = 0; i < MAX_DIGIT; ++i) factorial[i] = 0;

    // teraz przypisujemy do skrajnej prawej komórki 1, żeby móc zacząć liczyć silnię
    factorial[MAX_DIGIT - 1] = 1;

    // pętla z iteratorem będącym kolejnymi czynnikami w silni
    for (int i = 2;  i <= 500; i++)
    {
        // zmienna przechowująca to co jest ponad 9 w każdej komórce
        overflow = 0;
        // pętla lecąca przez całą liczbę
        for (int j = MAX_DIGIT - 1; j >= 0; --j)
        {
            // każdą "cyfrę" mnożymy przez liczbę i dodajemy to co jest przeniesione z wcześniejszej komórki
            // w pierwszej iteracji jest to zero, ponieważ oczywiście nic nie przenosimy
            factorial[j] = factorial[j] * i + overflow;
            // overflow to liczba dziesiątek w bieżącej komórce (jeżeli w komórce mamy 0…9 to dostajemy 0 i wszystko się zgadza)
            overflow = factorial[j] / 10;
        }
    }

    // teraz potrzebujemy wypisać naszą liczbę, żeby nei wypisywać nie znaczących zer to ustawiamy flagę! 
    bool non_zero = false;
    for (int i = 0; i < MAX_DIGIT; ++i)
    {
        if (factorial[i] != 0)
            non_zero = true;

        if (non_zero)
            cout << factorial[i];
    }

    cout << "\n";
    
    return 0;
}
