
// 1. Napisać program generujący elementy ciągu Fibonaciego mniejsze od miliona.
#include <iostream>
using namespace std;

// wersja dla 3 zmiennych 
int main()
{
    int f1 = 1, f2 = 1, f3 = 1;
    
    // wypisujemy pierwsze 2 elementy ciągu (z pewnością są one mniejsze od miliona ;) 
    cout << "1\n";


    while (f3 < 1000000)
    {
 
        // wyświetlamy ją
        cout << f3 << "\n"; 

         // wyliczamy kolejna liczbe fibonnaciego 
        f3 = f2 + f1;
        // na końcu pętli żeby zanim wyświetlimy sprawdzony został warunek
         // przesuwamy f2 = f1 na kolejne liczby;
        f1 = f2;
        f2 = f3;
    }

    return 0;
}

// wersja dla 2 zmiennych 
int main()
{
    int f1 = 1, f2 = 2;
    
    // wypisujemy pierwsze 2 elementy ciągu (z pewnością są one mniejsze od miliona ;) 
    cout << "1\n1\n";


    while (f2 < 1000000)
    {
        cout << f2 << "\n";         // wyświetlamy ją
        // do f2 przypisujemy kolejną liczbę z ciągu
        f2 += f1;
        f1 = f2 - f1;
    }

    return 0;
}
