/*
    ZESTAW 7
    ZADANIE 2
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int N = 6;

bool czyPierwsza(int n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i = i + 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool pocz(int T[N], int idx, int numb)
{
    
    if (idx == N) return true;

    for (int i = idx; (i < N) && (i < idx + 30); ++i)
    {
        numb = numb * 2 + T[i];

        if (czyPierwsza(numb))
        {
            if (pocz(T, i + 1, 0))
            {
                return true;
            }
        }
    }

    return false; 
    

    // jeżeli nigdzie nie zwróciliśmy true i wróciliśmy do pierwszego wywołania
    // to możemy z całą odpowiedzalnością zwrócić false
    if (idx == 0)   return false;
}



int main()
{
    int tab[N] = {1, 1, 0, 1, 0, 0};
    //for (int i = 0; i < N; ++i)
      //  tab[i] = i % 2;

    if (pocz(tab, 0, 0)) cout << "dziala\n";
    else cout << "nie\n";
    
    return 0;
}
