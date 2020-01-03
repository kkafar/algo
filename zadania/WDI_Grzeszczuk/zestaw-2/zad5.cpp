//Napisać program, który wyznacza ostatnia niezerową cyfra N! Program powinien
//działać dla N rzędu 1000000.

/// ZŁE ROZWIĄZANIE, NIE DZIAŁA JUŻ DLA N == 15
#include <iostream>

using namespace std;

int main()
{
    long long n, w = 1; 

    cin >> n; 

    for (int i = 1; i <= n; ++i)
    {
        w *= i;
        w = w % 1000;
        if (w & 10 != 0)
            w = w % 10;

        else
        {
            while (w % 10 == 0)
                w /= 10;
        }
        cout << w % 10 << "\n";
    }

    
    return 0;
}
