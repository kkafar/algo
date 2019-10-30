// 2. Znaleźć wyrazy początkowe zamiast 1,1 o najmniejszej sumie, aby w ciągu
// analogicznym do ciągu Fibonacciego wystąpił wyraz równy numerowi bieżącego roku.

#include <iostream>
using namespace std;

#define INF 999999

int main()
{
    int p1 = INF, p2 = INF, f1, f2;

    for (int i = 1; i < 2019; ++i)
    {
        for (int j = 2; j < 2019; ++j)
        {
            f1 = i; f2 = j; 
            while(f2 < 2019)
            {
                f2 = f2 + f1; 
                f1 = f2 - f1; 
            }
            if (f2 == 2019 && ((i + j) < (p1 + p2)))
            {
                p1 = i; p2 = j; 
            }
        }
    }

    cout << p1 << " " << p2 << "\n";
    return 0;
}
