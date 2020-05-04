/**
 * K. Kafara
 */

// TEN POTWÓR OCZYWIŚCIE NIE JEST ROZWIĄZANIEM, KTÓRE NAPISAŁBYM GDYBY TO NIE BYŁO KOLOKWIUM :D


#include <stdio.h>

int main(void)
{
    int n, numb;

    scanf("%d", &n);

    int T[n][n];

    int W[n][n];

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &T[i][j]);
            W[i][j] = 0;
        }
    }

    // obliczamy wartości tablicy W
    // najlepiej brzegi policzyć osobno, ale czas goni
    

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i - 1 >= 0 && j - 1 >= 0)
                W[i][j] += T[i - 1][j - 1];
            
            if (i - 1 >= 0)
                W[i][j] += T[i - 1][j];

            if (i - 1 >= 0 && j + 1 < n)
                W[i][j] += T[i - 1][j + 1];

            if (j - 1 >= 0)
                W[i][j] += T[i][j - 1];

            if (j + 1 < n)
                W[i][j] += T[i][j + 1];
            
            if (i + 1 < n && j - 1 >= 0)
                W[i][j] += T[i + 1][j - 1];
            
            if (i + 1 < n)
                W[i][j] += T[i + 1][j];

            if (i + 1 < n && j + 1 < n)
                W[i][j] += T[i + 1][j + 1];
        }
    }

/*     for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d ", T[i][j]);
        
        printf("\n");
    }*/

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%d ", W[i][j]);
        
        printf("\n");
    } 
    return 0;
}
