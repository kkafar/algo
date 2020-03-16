/**
 * K. Kafara
 */

#include <stdio.h>

enum BOOL {true = 1, false = 0};

typedef enum BOOL bool;

bool is_prime(int n)
{
    if (n == 2) return true;

    if (n < 2 || (n % 2 == 0)) return false;

    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0) return false;

    return true;
}

bool ascending(int n)
{
    int last_digit, sec_last_digit = 10;
    while (n > 0)
    {
        last_digit = n % 10;
        
        if (last_digit > sec_last_digit) return false;

        n /= 10;
        sec_last_digit = last_digit;
    }

    return true;
}


int main(void)
{
    int n;

    scanf("%d", &n);

    if (n > 2)
    {
        printf("2\n");

        for (int i = 3; i < n; i += 2)
        {
            if (is_prime(i) == true && ascending(i) == true)
                printf("%d\n", i);
        }
    }
    return 0;
}   

