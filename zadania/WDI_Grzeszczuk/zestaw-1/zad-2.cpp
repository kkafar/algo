//  2. Znaleźć najmniejsze wyrazy początkowe zamiast 1,1 aby w ciągu analogicznym do ciągu
//  Fibonacciego wystąpił w nim wyraz równy numerowi bieżącego roku.

/* Czy wyrazy początkowe 2, 2 są mniejsze od 1, 3? Jak rozumieć to zadanie? Postaram się przyjąć porządek leksykograficzny */ 

// Nieco go zmodyfikuję, wypiszemy wszystkie takie podstawy

#include <iostream>
using namespace std;

int main()
{
    // najmniejsze 2 początkowe wyrazy większe od wyrazów początkowych ciągu fibonnaciego
    int p1 = 1, p2 = 2, c1 = 1, c2 = 2; 
    bool flag = true;

    while (p1 < 2019 && p2 < 2019)
    {
       // cout << "WP: " << p1 << " " << p2 << "\n";
        while (c2 < 2019 )
        {
            c2 += c1;
            c1 = c2 - c1;
        } 

        if (c2 == 2019 && flag)
        {
            cout << p1 << " " << p2 << "\n";
            flag = false;
        }

        // jeżeli przy danej podstawie w ciągu nie ma wyrazu o wartości 2019, to potrzebujemy zmienić podstawę
        else
        {
            // coś było zmienione więc zmieniamy flagę 
            flag = true;
            // 2018 - bo nie chcemy dostać 2019
            if (p2 < 2018) 
            {
                ++p2;
                c2 = p2;
                c1 = p1;
            }

            else if (p2 == 2018)
            {
                if (p1 < 2018)
                {
                    ++p1; 
                    p2 = 1;
                    c2 = p2; 
                    c1 = p1;
                }

                // gdy p1 == 2018
                else
                {
                    // to już na pewno coś poszło nie tak;
                    return -1;
                }
            }

        }
    }

    return 0;
}
