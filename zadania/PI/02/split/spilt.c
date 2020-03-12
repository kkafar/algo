/**
  * K. Kafara
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
    int n, odd = 0, even = 0;

    scanf("%d", &n);

    int T1[n];

    for (int * i = T1; i < T1 + n; ++i)
    {
        scanf("%d", i);
        if (((*i) & 1) == 0)  ++even;
        else                ++odd;
    }

    int T2[even], T3[odd];

    for (int * i = T1, *j = T2, *k = T3; i < T1 + n; ++i)
    {
        if (((*i) & 1) == 0)  (*j++) = (*i);
        else                (*k++) = (*i);
    }

    q_sort(T2, 0, even - 1);
    q_sort(T3, 0, odd - 1);
    
    printf("%d %d\n", even, odd);

    for (int * i = T2; i < T2 + even; ++i)
        printf("%d\n", *i);
    
    for (int * i = T3; i < T3 + odd; ++i)
        printf("%d\n", *i);

    return 0;
}
