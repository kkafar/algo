/* 
    ZESTAW 3 
    ZADANIE 2
    2.  Napisać program wczytujący dwie liczby naturalne i odpowiadający
        na pytanie czy są one zbudowane z takich samych cyfr, np. 123 i
        321, 1255 i 5125, 11000 i 10001.
*/

#include <iostream>
#include <string>
using namespace std;

void print_tab(int n, int T[])
{
    for (int i = 0; i < n; ++i)
        cout << T[i] << " ";
    cout << "\n";
}

int main()
{
    // trzymamy sobie licznik cyfr które wystąpiły w liczbie 1, jeżeli jakaś była to digits[cyfra]++; 
    // taki zapis powinien całą tablicę zainicjalizować zerami
    int digits_1[9], digits_2[9];
    for (int i = 0; i < 10; ++i) digits_1[i] = digits_2[i] = 0;

    int numb1, numb2;

    cin >> numb1 >> numb2;

    while (numb1 > 0)
    {
        ++digits_1[numb1 % 10];
        numb1 /= 10;
    } 
    while (numb2 > 0)
    {
        ++digits_2[numb2 % 10];
        numb2 /= 10; 
    }
    // skoro mamy już ilości wystąpień poszczególnych cyfr każdej z liczb, to potrzebujemy
    // porównać czy wszystkie ilości się zgadzają
    for (int i = 0; i < 10; ++i)
    {
        if (digits_1[i] != digits_2[i])
        {
            cout << "NIE!\n";
            return 0;
        }
    }

    cout << "TAK!\n";

    return 0;
}
