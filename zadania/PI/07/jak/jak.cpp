/* K. Kafara */

#include <stdio.h>
#include <vector>
#include <queue>

// wersja 1, macierz sąsiedztwa + graf nieskierowany


const int MAX_INT_32 = 2147483647;


void floyd_warshall(int ** S, int n)
{
    int distance;
    for (int t = 0; t < n; ++t)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                // jeżeli odpowiedznie krawędzie istnieją
                if (S[i][t] != MAX_INT_32 && S[t][j] != MAX_INT_32)
                {
                    distance = S[i][t] + S[t][j];
                    if (S[i][j] > distance)
                        S[i][j] = distance;
                }
            }
        }
    }
}

int main()
{
    int n, lines, queries, stations, nr, time, last_station;

    scanf("%d %d %d", &n, &lines, &queries);


    int ** S = new int * [n];
    for (int i = 0; i < n; ++i)
        S[i] = new int[n];   
    

    // przygotowujemy macierz najkrótszych ścieżek oraz macierz wag
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            S[i][j] = MAX_INT_32;
        }
        
        S[i][i] = 0;
    }

    for (int i = 0; i < lines; ++i)
    {
        scanf("%d %d", &stations, &last_station);

        for (int j = 0; j < stations - 1; ++j)
        {
            scanf("%d %d", &time, &nr);
            if (time < S[last_station][nr])
            {
                S[last_station][nr] = S[nr][last_station] = time;
            }
            last_station = nr;
        }
    }
    
    floyd_warshall(S, n);

    for (int i = 0; i < queries; ++i)
    {
        scanf("%d %d", &nr, &time);
        printf("%d\n", S[nr][time]);   
    }

    for (int i = 0; i < n; ++i)
        delete[] S[i];

    delete[] S;
    return 0;
}
