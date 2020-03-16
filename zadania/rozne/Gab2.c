/**
 * K. Kafara
 */

#include <stdio.h>


int * func(float * a, float * b)
{
    int * result_ptr = (int *) malloc(sizeof(int));
    (*result_ptr) = (int)((*a) * (*b));
    return result_ptr;
}

int main()
{
    float a, b;

    scanf("%f %f", &a, &b);

    printf("%d\n", *(func(&a, &b)));
    return 0;
}
