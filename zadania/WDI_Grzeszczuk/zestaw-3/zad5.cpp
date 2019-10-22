#include <iostream>
using namespace std;
const int MAX_DIGIT = 3000;
int main()
{
    // jeżeli chcemy większą liczbę to podmieniamy MAX_DIGIT po prostu
    int digits[MAX_DIGIT], zeroes = 0;
    bool sys_flag;
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

        digits[MAX_DIGIT - 1] -= 1;
        for (int i = MAX_DIGIT - 1; digits[i] < 0; --i)
        {
            // jeżeli dana cyfra jest mniejsza od zera, to tylko wtedy ta pęlta się wykonuje, więc nie trzeba sprawdzać
            // żadnym ifem, a przynajmniej tak mi się wydaje
            digits[i] += 10;
            digits[i - 1] -= 1;
        }
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
