/* 
    ZESTAW 3
    ZADANIE 4
    4.   Napisać program obliczający i wypisujący wartość N! dla N z
         zakresu od 1 do 1000.
*/

#include <iostream>
#include <iomanip>
using namespace std;
const int MAX_DIGIT = 3000;
int main()
{
    // jeżeli chcemy większą liczbę to podmieniamy MAX_DIGIT po prostu
    int digits[MAX_DIGIT], zeroes = 0;
    for (int i = 0; i < MAX_DIGIT; ++i) digits[i] = 0;
    digits[MAX_DIGIT - 1] = 1;
    int overflow = 0; 

    for (int j = 1; j <= 1000; ++j)
    {
        // przejeżdżam przez całą liczbę 
        for (int i = MAX_DIGIT - 1; i >= 0; --i)
        {
            if (digits[i] != 0)
            {
                digits[i] *= j;
            }
        }
        // teraz przepisuję wszystko co jest ponad 10 do kolejnych komórek (po lewej)
        for (int i = MAX_DIGIT - 1; i >= 1; --i)
        {
            if (digits[i] >= 10)
            {
                overflow = (digits[i] - digits[i] % 10) / 10;
                digits[i - 1] += overflow;
                digits[i] = digits[i] % 10;
            }
        }
        /*zeroes = 0;
        cout << j << ": ";
        for (int i = 0; i < MAX_DIGIT; ++i)
        {
            if (digits[i] == 0)
                ++zeroes;
            else
                break;
        }
        for (int i = zeroes; i < MAX_DIGIT; ++i)
            cout << digits[i];
        cout << "\n";*/
    }

        zeroes = 0;
        for (int i = 0; i < MAX_DIGIT; ++i)
        {
            if (digits[i] == 0)
                ++zeroes;
            else
                break;
        }
        for (int i = zeroes; i < MAX_DIGIT; ++i)
            cout << digits[i];
        cout << "\n";

    return 0;
}
