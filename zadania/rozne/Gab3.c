/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>
/* Muszą być >= 4 kolumny, bo tak w zadaniu jest wymuszone (w parametrach funkcji print_tab()) */
#define COL 4
// Liczba wierszy bodaj dowolna
#define ROW 4

void print_tab(int A[][4], int x)
{
    int i, j;
    for (i = 0; i < x; ++i)
    {
        for (j = 0; j < 4; ++j)
            printf("%3d", A[i][j]);
        
        printf("\n");
    }
}


void wypisz_i(int * b, int * e)
{
    while (b < e)
        printf("%4d", *b++);
    printf("\n");
}


int main(void)
{
    // Tworzenie tablicy array1 (tablicy przechowującej wskaźniki na poszczególne wiersze)
    int ** array1 = (int**) calloc(ROW, sizeof(int*));

    // Do każdego wskaźnika na wiersz de facto przypisujemy wiersz
    for (int i = 0; i < ROW; ++i)
        array1[i] = (int*) calloc(COL, sizeof(int));

    for (int i = 0; i < ROW; ++i)
        wypisz_i(array1[i], array1[i] + COL);

    for (int i = 0; i < ROW; ++i)
        free(array1[i]);
    
    free(array1);
    
    return 0;
}   
