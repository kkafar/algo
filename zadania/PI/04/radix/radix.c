/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void coutning_sort(char** A, int n, int k, char** res)
{
    // tablica do zliczania wystąpień poszczególnych cyfr
    // statyczna, żeby nie rezerwować od nowa pamięci na stosie przy każdym wywołaniu 
    static int digits[10];

    for (int* ptr = digits; ptr < digits + 10; ++ptr)
        *ptr = 0;
    
    // zliczamy wystąpienia poszczególnych cyfr (jedziemy po cyfrach na indeksie k-tym)
    for (int i = 0; i < n; ++i)
        ++digits[A[i][k] - '0'];

    // 
    for (int i = 1; i < 10; ++i)
        digits[i] += digits[i - 1];
    

    int digit;
    for (int i = n - 1; i >= 0; --i)
    {
        // pobieramy cyfrę
        digit = A[i][k] - '0';
        // wpisujemy do tablicy wynikowej wiersz z pobraną cyfrą 
        // najpierw odejmując, sprawiamy że od razu trafiamy na odpowiedni indeks
        res[--digits[digit]] = A[i];
    }

    // na końcu pozostaje przepisać zawartość tablicy wynikowej do tablicy wyjściowej
    for (int i = 0; i < n; ++i)
        A[i] = res[i];

}


void radix_sort(char** A, int n, int k, char** res)
{
    --k;
    while (k >= 0)
        coutning_sort(A, n, k--, res);
}

int main(void)
{
    int z, n, k;

    scanf("%d", &z);

    for (int i = 0; i < z; ++i)
    {
        scanf("%d %d", &n, &k);

        // tablica liczb (każda liczba to tablica charów))
        char** A = (char**) malloc(n * sizeof(char*));

   
        for (char ** ptr = A; ptr < A + n; ++ptr)
            *ptr = (char*) malloc(k * sizeof(char));
        


        for (int i = 0; i < n; ++i)
            scanf("%s",  A[i]);

        // tworzymy także tablicę wyników
        char** res = (char**) malloc(n * sizeof(char*));


        radix_sort(A, n, k, res);


        for (int i = 0; i < n; ++i)
            printf("%s\n", A[i]);

        // zwalnianie pamięci po każdym przypadku
        for (int i = 0; i < n; ++i)
            free(*(A + i));
        
        free(A);
    }
    return 0;
}
