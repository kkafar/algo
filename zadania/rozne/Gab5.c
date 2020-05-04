/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

// maksymalna długoś pojedynczego stringa
#define SIN_STR_LEN 100

// number of strings
#define NOS 2

void va_cat(char ** result, int num, ...)
{
    va_list vl;
    char * sin_str;
    va_start(vl, num);

    for (int i = 0; i < num; ++i)
    {
        sin_str = va_arg(vl, char *);
        result[i] = sin_str;
    }

    printf("%s\n%s\n",  result[0], result[1]);
}

int main(void)
{
    char ** str_table = (char **) malloc(sizeof(char *) * NOS);
    
    for (int i = 0; i < NOS; ++i)
        str_table[i] = (char *) malloc(sizeof(char) * SIN_STR_LEN);


    char * str_1 = "String1", * str_2 = "String2";

    va_cat(str_table, 2, str_1, str_2);

    for (int i = 0; i < NOS; ++i)
        free(str_table + i);

    //free(str_table);

    return 0;
}
