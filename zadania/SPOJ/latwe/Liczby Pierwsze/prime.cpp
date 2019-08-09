// link do zadania: https://pl.spoj.com/problems/PRIME_T/

#include <stdio.h>
 
int main()
{
    int n, m;
    bool czyPierwsza;
 
    scanf("%d", &n);
 
    for (int i = 0; i < n; ++i) {
        scanf("%d", &m);
 
        czyPierwsza = true;
 
        if (m <= 1) {
            printf("NIE\n");
            continue;
        }
 
        for (int j = 2; j*j <= m; ++j) {
            if (m % j == 0) {
                czyPierwsza = false;
                break;
            }
 
            else
                czyPierwsza = true;
        }
 
        if(czyPierwsza)
            printf("TAK\n");
 
        else
         printf("NIE\n");
 
    }
 
    return 0;
}
