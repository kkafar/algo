/**
  * K. Kafara
  * Dane są dwie tablice liczb całkowitych, T1 i T2, o długościach odpowiednio m i n. Napisz
  * program, który na wejściu otrzymuje wartości obu tablic i sortuje je rosnąco. Następnie
  * utwórz nową tablicę, T3, o długości co najwyżej m + n, która powstaje przez połączenie
  * tablic T1 i T2 w taki sposób, aby:
  * 1. Zachować rosnące uporządkowanie wartości tablicy
  * 2. Wartości tablicy T3 były unikalne
  */

#include <stdio.h>

void int_swap(int * a, int * b)
{
    int buff = *a;
    (*a) = (*b);
    (*b) = buff;
}

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

void q_sort(int * arr, int p, int q)
{
    if (p < q)
    {
        int pvt = partition(arr, arr + p, arr + q);
        q_sort(arr, p, pvt - 1);
        q_sort(arr, pvt + 1, q);
    }
}

int main()
{ 
    int n, m; 

    scanf("%d %d", &m, &n);

    int T1[m], T2[n];

    for (int * i = T1; i < T1 + m; ++i)
        scanf("%d", i);
    
    for (int * i = T2; i < T2 + n; ++i)
        scanf("%d", i);

    q_sort(T1, 0, m - 1);
    q_sort(T2, 0, n - 1);

    int * T3 = (int *) malloc((m + n) * sizeof(int));

    int * ptr1 = T1, * ptr2 = T2, * ptr3 = T3, last_val = -1;

    while ((ptr1 < T1 + m) && (ptr2 < T2 + n))
    {
        if ((*ptr1) <= (*ptr2))
        {
            if ((*ptr1) == last_val)
                ++ptr1;
                
            else
            {
                (*ptr3) = (*ptr1++);
                last_val = (*ptr3++);
            }
        }
        else
        {
            if ((*ptr2) == last_val)
                ++ptr2;
            
            else
            {
                (*ptr3) = (*ptr2++);
                last_val = (*ptr3++);
            }
        }
    }

    while (ptr1 < T1 + m)
    {
        if ((*ptr1) == last_val)
            ++ptr1;
            
        else
        {
            (*ptr3) = (*ptr1++);
            last_val = (*ptr3++);
        }
    }

    while (ptr2 < T2 + n)
    {
        if ((*ptr2) == last_val)
            ++ptr2;
            
        else
        {
            (*ptr3) = (*ptr2++);
            last_val = (*ptr3++);
        }
    }

    for (int * i = T3; i < ptr3; ++i)
        printf("%d\n", *i);
    
    free(T3);
    return 0;
}
