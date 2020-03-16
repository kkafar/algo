/**
 * K. Kafara
 */

#include <stdio.h>
#include <stdlib.h>

/**
 * \brief Zwraca wskaźnik do zmiennej całkowitej przechowującej podłogę z iloczynu przesłanych wartości
 * \param Czynnik iloczynu
 * \param Czynnik iloczynu
 * \return (int*) wskaźnik
 */
int * func(float * a, float * b)
{
    // Rezerwacja miejsca w pamięci na zmienną typu całkowitego
    // Przypominam, że mallloc zwraca (void *) ==> niby nie trzeba, ale powinno się to
    // zrzutować na (int *). 
    int * result_ptr = (int *) malloc(sizeof(int));

    // jeżeli nie udało się zarezerwować pamięci to zwracamy wartość NULL
    if (result_ptr == NULL) return NULL;

    // obliczamy podłogę: 
    // 1. obliczamy wartość iloczynu
    // 2. rzutujemy wynik na typ całkowity (z tego co kojarzę to po prostu obcina wszystko co po przecinku)
    // czyli to co chcemy osiągnąć. 
    (*result_ptr) = (int)((*a) * (*b));
    return result_ptr;
}

int main()
{
    float a, b;

    scanf("%f %f", &a, &b);

    int * result = func(&a, &b);
    
    if (result == NULL) 
        printf("Nie udalo sie zarezerwowac pamieci!\n");
    else
    {
        printf("%d\n", *result);
        free(result);    
    }
    
    return 0;
}
