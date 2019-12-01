/*
ZESTAW 3, ZADANIE 14
14. Proszę napisać program, który wypełnia tablice int tab[MAX]
trzycyfrowymi liczbami pseudolosowymi, a następnie wyznacza i
wypisuje długość najdłuższego podciągu spójnego znajdującego się
w tablicy dla którego w tablicy występuje również rewers tego
ciągu. Na przykład dla tablicy: 2,9,3,1,7,11,9,6,7,7,1,3,9,12,15
odpowiedzią jest liczba 4.
*/

#include <iostream>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 15;

// w ufności że ta funkcja działa
bool rewers(int T[N], int l, int p)
{
    bool flaga = false;
    for (int i = N - 1; i >= p - l; --i)
    {
        if (T[i] == T[l])
        {
            flaga = true;
            for (int j = l, k = i; j <= p; ++j, --k)
            {
                if (T[j] != T[k])
                {
                    flaga = false;
                    break;
                }
            }
            if (flaga) return true;
        }
    }
    return flaga;
}

int main()
{
    int T[N] = {8, 7, 6, 5, 5, 3, 3, 2, 6, 4, 4, 5, 6, 7, 8};
    int maxdl = 1;
    
    for (int i = 0; i <= N - maxdl; ++i)
    {
        for (int j = i + 1; j < N; ++j)
        {
            if (rewers(T, i, j))
            {
                if (j - i + 1 > maxdl) maxdl = j - i + 1;
            }
        }
    }

    cout << maxdl << "\n";
    return 0;
}
