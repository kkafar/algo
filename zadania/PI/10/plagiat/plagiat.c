/* K. Kafara */

#include <stdio.h>
#include <string.h>

void clear_buff(void)
{
    while ((getchar()) != '\n');
}

int get_str(char str[])
{
    char a = ' ';
    int len = 0;
    while (a != '\n')
    {
        a = getchar();
        str[len] = a;
        ++len;
    }
    str[len - 1] = '\000';
    return (len - 1);
}

int min(int a, int b, int c)
{
    // printf("%d %d %d\n", a, b, c);
    if (a <= b)
    {
        if (a <= c)
            return a;
        else 
            return c;
    }
    else
    {
        if (b <= c)
            return b;
        else 
            return c;
    }
    
}

int main(void)
{
    char str1[202], str2[202];

    int dp_table[203][203];

/*     fgets(str1, 201, stdin);
    fgets(str2, 201, stdin);
 */

    // fgets wstawia na koniec stringa znak nowej linii ==> to będzie nasz terminating character w pętlach programu
    
    register int len1 = get_str(str1);
    register int len2 = get_str(str2);
 
    if (len1 == 0 && len2 == 0)
    {
        printf("%d\n", 0);
        return 0;
    }
    else if (len1 == 0 && len2 != 0)
    {
        printf("%d\n",  len2);
        return 0;
    }
    else if (len1 != 0 && len2 == 0)
    {
        printf("%d\n", len1);
        return 0;
    }

    // printf("%d %d\n", len1, len2);

    // uzupełniamy pierwszy wiersz i pierwszą kolumnę (odległość edycyjna pustego "" od str[0...n])
/*     while (*ch1++ != '\n')
    {
        dp_table[len1][0] = len1;
        ++len1;
    }

    while (*ch2++ != '\n')
    {
        dp_table[0][len2] = len2;
        ++len2;
    } */

    for (int i = 0; i <= len1; ++i)
    {
        dp_table[i][0] = i;
    }
    for (int i = 0; i <= len2; ++i)
    {
        dp_table[0][i] = i;
    }       

/*     printf("%s %d\n%s %d\n", str1, len1, str2, len2);

    printf("------------------------------------------\n");
    for (int i = 0; i <= len1; ++i)
    {
        for (int j = 0; j <= len2; ++j)
            printf("%3d", dp_table[i][j]);
        printf("\n");
    }
    printf("------------------------------------------\n"); */

    int cost;
    for (int r = 1; r <= len1; ++r)
    {
        for (int c = 1; c <= len2; ++c)
        {    
            if (str1[r - 1] == str2[c - 1])
                cost = 0;
            else 
                cost = 1;

            dp_table[r][c] = min(dp_table[r - 1][c] + 1, dp_table[r][c - 1] + 1, dp_table[r - 1][c - 1] + cost);
        }

/*         printf("------------------------------------------\n%d\n", r);
        for (int i = 0; i <= len1; ++i)
        {
            for (int j = 0; j <= len2; ++j)
                printf("%3d", dp_table[i][j]);
            printf("\n");
        }
        printf("------------------------------------------\n"); */
    }
/* 
    for (int i = 0; i < len1; ++i)
    {
        for (int j = 0; j < len2; ++j)
            printf("%d ", dp_table[i][j]);

        printf("\n");
    }
*/

    printf("%d\n", dp_table[len1][len2]);
    return 0;
}
