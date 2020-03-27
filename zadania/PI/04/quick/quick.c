/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * Przyjmuje adresy zmiennych
 */
void int_swap(int * a, int * b)
{
    int buff = *a;
    (*a) = (*b);
    (*b) = buff;
}

// quick_sort
/// ===========================================
int partition(int * arr, int * p, int * q)
{
    // LOG_TAB(p, q - p + 1, "FRAG:");

    // na  pivot wybieramy ostatni element
    int pvt = *q;
    // ustawiamy się adres wcześniej
    int * i = p - 1; 

    for (int * j = p; j < q; ++j)
        if ((*j) <= pvt)
            int_swap(++i, j);
    
    int_swap(++i, q);

    // LOG_TAB(p, q - p + 1, "RES:");

    return i - arr;
}

/**
 * Sortuje przekazaną tablicę (lub jej wyszczególniony fragment)
 * \param arr - wsk, do pierwszego elementu tablicy do posortowania
 * \param p - początek przedziału do posortowania (indeks)
 * \param q - koniec przedziału do posortowania (indeks)
 */
void q_sort(int * arr, int p, int q)
{
    if (p < q)
    {
        int pvt = partition(arr, arr + p, arr + q);
        q_sort(arr, p, pvt - 1);
        q_sort(arr, pvt + 1, q);
    }
}
/// ===========================================

int main(void)
{
    int z, n; 

    scanf("%d", &z);

    for (int i = 0; i < z; ++i)
    {
        scanf("%d", &n);

        int A[n];

        for (int j = 0; j < n; ++j)
            scanf("%d", A + j);

        q_sort(A, 0, n - 1);

        for (int i = 0; i < n; ++i)
            printf("%d\n", *(A + i));
    }
    return 0;
}
