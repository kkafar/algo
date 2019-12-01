/*
Zadanie 1.1a kolos 2015 ad-wdi-kl-a, wtorek, 3 listopada 2015
1) Proszę napisać program, który wczytuje liczbę naturalną A i odpowiada na pytanie: ,,czy w którymkolwiek
z systemów o podstawie 2-16, wszystkie cyfry liczby A zapisanej w tym systemie, są liczbami pierwszymi?".
*/

#include <iostream>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 20;

bool isAllPrime(bool digits[16])
{
    REP(i, 16)
    {
        if (digits[i])
        {
            if (!(i == 2 or i == 3 or i == 5 or i == 7 or i == 11 or i == 13))
                return false;
        }
    }
    return true;
}

int main()
{
    int A = 18, a;
    int maxSysBase = 16, sysBase = 2;
    bool digits[16];

    REP(i, 16) digits[i] = false;

    while (sysBase <= maxSysBase)
    {
        a = A;
        while (a > 0)
        {
            digits[a % sysBase] = true;
            a /= sysBase;
        }

        if (isAllPrime(digits))
        {
            cout << "TAK! Dla: " << sysBase << "\n";
            return 0;
        }

        else
        {
            ++sysBase;
            REP(i, 16) digits[i] = false;
        }
    }

    cout << "NIE!\n";
    
    return 0;
}
