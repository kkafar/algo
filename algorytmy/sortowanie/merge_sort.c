#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "utility_c.h"

#define SIZE 20


void merge(int * arr, int p, int s, int q)
{
    // LOG_TAB("larr: ", arr + p, s - p + 2, print_tab);
    // LOG_TAB("rarr", arr + s + 1, q - s + 1, print_tab);

    int * p_ptr = arr + p, * s_ptr = arr + s, * q_ptr = arr + q;
    // s - p + 1 + 1
    int larr[s - p + 2];
    // q - (s + 1) + 1
    int rarr[q - s + 1];
    // początek prawego przedziału 
    int * r_ptr = s_ptr + 1;
    // dodajemy wartownikow
    larr[s - p + 1] = 2000;
    rarr[q - s] = 2000;

    // przepisujemy tablice
    for (int * ptr = p_ptr, *larr_ptr = larr; ptr <= s_ptr; ++ptr, ++larr_ptr)
        (*larr_ptr) = (*ptr);

    for (int * ptr = r_ptr, *rarr_ptr = rarr; ptr <= q_ptr; ++ptr, ++rarr_ptr)
        (*rarr_ptr) = (*ptr);


    for (int * ptr = p_ptr, *larr_ptr = larr, *rarr_ptr = rarr; ptr <= q_ptr; ++ptr)
    {
        if ((*larr_ptr) <= (*rarr_ptr)) 
        {
            (*ptr) = (*larr_ptr);
            ++larr_ptr;
        }

        else
        {
            (*ptr) = (*rarr_ptr);
            ++rarr_ptr;
        }
    }
}

void m_sort(int * arr, int p, int q)
{
    if (p < q)
    {
        int mid = (p + q) / 2;
        m_sort(arr, p, mid);
        m_sort(arr, mid + 1, q);
        merge(arr, p, mid, q);
    }
}

int main()
{

    srand(time(NULL));

    
    int arr[SIZE];
    for (int * i = arr; (i) < (arr + SIZE); ++i)
        (*i) = ((int)(rand())) % 1000 ;
    
    print_tab(arr, SIZE);

    m_sort(arr, 0, SIZE - 1);

    print_tab(arr, SIZE); 

    return 0;
}
