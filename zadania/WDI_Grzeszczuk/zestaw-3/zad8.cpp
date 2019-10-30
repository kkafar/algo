/* 
    ZESTAW 3
    ZADANIE 8

    ALGORTYM NIE BYŁ W OGÓLE TESTOWANY!!!!
    + skopiować treść do opisu
*/

#include <iostream>

using namespace std;

const int MAX = 1000;

// godny wyśmiania generator liczb pseudolosowych
/*
    By prowadzący: 
    f(x) = 1372981 * x + 345124
    g(x) = f(x) % 997 (jakaś pierwsza) (bo pierwsza jest w możliwie najmniejszej ilośc rozkładów innych
    liczb :D (albo coś takiego :D))


    Zadanko dla ambitnych: 
    jak złamać taki generator
*/


bool onlyOdd(int n)
{
    // po prostu bierzemy modulo 2 każdą cyfrę, jeżeli choć raz pojawi się 0 to znaczy
    // że jest choć jedna cyfra parzysta => retrun false

    while (n > 0)
    {
        if (n % 2 == 0)
            return false;

        n /= 10;
    }

    return true;
}

int main()
{
    int T[MAX]; // TODO wypełnić w jkaiś sposób losowymi (bez rand())

    for (int i = 0; i < MAX; ++i)
    {
        if (onlyOdd(T[i]))
        {
            cout << "TAK\n";
            return 0;
        }
    }

    // jezeli jesteśmy tutaj, to znaczy że żadna nie spełniła warunków zadania
    cout << "NIE\n";

    return 0;
}
