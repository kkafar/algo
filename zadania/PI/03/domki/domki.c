/**
 * K. Kafara
 */

#include <stdio.h>

int main(void)
{
    int n;

    scanf("%d", &n);
    
    int arr[n];

    int arr_sum = 0;
    
    for (int * i = arr; i < arr + n; ++i)
    {  
        scanf("%d", i);
        arr_sum += *i;
    }

    int larr_sum = 0;
    int idx = -1;
    for (int * i = arr; i < arr + n; ++i)
    {
        if (larr_sum == (arr_sum - larr_sum - (*i)))
        {
            idx = i - arr;
            break;
        }

        larr_sum += *i;
    }

    printf("%d", idx);

    return 0;
}   

