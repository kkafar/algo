/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * SPECYFIKACJA ZADANIA JEST ZŁA!
 * Odpowiedź (aby została zaakceptowana przez sprawdzarkę) nie może zawierać ilości
 * unikalych wartości w pierwszej linii wyjścia, przeciwnie do tego co jest podane w specyfikacji
 * (chociaż przykładowe wyjście jest dobrze zrobione)
 */

struct Pair
{
    int key, count;
};

int main(void)
{
    int n;

    scanf("%d", &n);
    int found = 0, val_count = 0;
    int * T = (int *) malloc(n * sizeof(int));
    struct Pair * P = (struct Pair *) malloc(n * sizeof(struct Pair));

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", T + i);
        for (int j = 0; j < val_count && found == 0; ++j)
        {
            if (P[j].key == T[i])
            {
                // printf("Powtorzony %d\n", T[i]);
                ++(P[j].count);
                found = 1;
            }
        }
        if (found == 0)
        {
            // printf("Dodaje %d\n", T[i]);
            P[val_count].key = T[i];
            P[val_count++].count = 1;

        }
        found = 0;
    }

    //printf("%d\n", val_count);
    for (int i = 0; i < val_count; ++i)
    {
        printf("%d %d\n", P[i].key, P[i].count);
    }

    free(P);
    free(T);
    return 0;
}
