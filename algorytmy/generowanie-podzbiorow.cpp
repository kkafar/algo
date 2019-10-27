/* 
    Generowanie k-elementowych podzbiorów zbioru n-elementowego

    KONIECZNIE TO OKOMENTOWAĆ
*/

#include <iostream>
#include <iomanip>

using namespace std;

void printTab(int * T, int n)
{
    static int k = 1;
    cout << setw(5) << k << "     ";
    for (int i = 0; i < n; ++i)
        cout << T[i] << " ";
    cout << "\n";
    ++k;
}

int main()
{
    int n, k, j;
    cin >> n >> k;

    int * T = new int[k];

    for (int i = 0; i < k; ++i)
        T[i] = i + 1;

    // formatowanie wyjścia
    cout << "Lp.     Permutacja\n";

    do
    {
        printTab(T, k);

        if (T[k - 1] < n)
            j = k - 1;

        else
            j = k - 2; 

        while (j >= 0 && T[j] + 1 == T[j + 1])
            --j;

        if (j >= 0)
        {
            ++T[j];
            for (int i = j + 1; i < k; ++i)
            {
                T[i] = T[i - 1] + 1; 
            }
        }    

    } while (j >= 0);

    delete[] T;
    return 0;
}
