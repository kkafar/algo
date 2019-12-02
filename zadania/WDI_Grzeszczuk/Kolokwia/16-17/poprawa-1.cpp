/*
KOLOS POPRAWKOWY 2016/2017
1. Dana jest tablica int t[N][N] zawierająca liczby naturalne. Dokładnie w jednym
wierszu, bądź kolumnie znajduje się fragmentu ciągu arytmetycznego o długości
większej niż 2, którego elementy są liczbami pierwszymi. Proszę napisać funkcję
która zwróci długość tego ciągu.
*/

#include <iostream>
#include <iomanip>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 5;
const int INF = 2000000000;

int T[N][N] = 
{
    {1, 2, 3, 4, 1},
    {1, 3, 9, 7, 9},
    {2, 5, 1, 5, 9},
    {0,77, 0, 0, 7}, 
    {0, 1, 1, 1, 2}
};

bool is_prime(int n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;

    return true;
}

bool war_poz(int T[N][N], int i, int j)
{
    if (is_prime(T[i][j]) and is_prime(T[i][j - 1]) and is_prime(T[i][j - 2]) and
        (T[i][j] - T[i][j-1] == T[i][j-1] - T[i][j-2])) 
        return true;
    else
        return false;
}
bool war_pion(int T[N][N], int i, int j)
{
    if (is_prime(T[i][j]) and is_prime(T[i-1][j]) and is_prime(T[i-2][j]) and
        (T[i][j] - T[i - 1][j] == T[i-1][j] - T[i-2][j]))
        return true;
    else
        return false;
}

int func(int T[N][N])
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 2; j < N; ++j)
        {
            if (war_poz(T, i, j))
            {
                int x;
                for (x = j + 1; x < N && war_poz(T, i, x); ++x);
                return ((x-1) - (j-2) + 1);
            }
            if (war_pion(T, j, i))
            {
                int x; 
                for (x = j + 1; x < N && war_pion(T, x, i); ++x);
                return ((x-1) - (j-2) + 1);
            }
        }
    }
    return -1;
}

int main()
{
    cout << func(T) << "\n";
    return 0;
}
