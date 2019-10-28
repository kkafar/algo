#include <iostream>

using namespace std;


// funkcja zwracająća nwd, na podstawie algorytmu euklidesa
int nwd(int a, int b)
{

    while (a > 0 && b > 0)
    {
        if (a >= b)
            a -= b;

        else 
            b -= a;
    }

    return b + a;
}

int nww(int a, int b)
{
    // taka kolejność  żeby była mniejsza szansa wyjścia poza zakres
    // najpierw dzielimy ==> potem mnożymy mniejsze liczby 
    return a / nwd(a, b) * b;
}
