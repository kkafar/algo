/*
Zadanie 2 (2014/15)
Dane są dwie liczby naturalne z których budujemy trzecią liczbę. W budowanej liczbie muszą
wystąpić wszystkie cyfry występujące w liczbach wejściowych. Wzajemna kolejność cyfr każdej z
liczb wejściowych musi być zachowana.
Na przykład mając liczby 123 i 75 możemy zbudować liczby 12375, 17523, 75123, 17253, itd.
Proszę napisać funkcję która wyznacza ile liczb pierwszych można zbudować z dwóch zadanych
liczb.

No i tu jest mały problem z moim algorytmem, bo co gdy w liczbie jest zero? 
Poza tym chyba działa ok;
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 3;

bool isPrime(int n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    for (int i = 3; i * i <= n; i = i + 2)
       if (n % i == 0) return false;
    
    return true;    
}

int rev(int n)
{
    int reversed = 0;
    while (n > 0)
    {
        reversed = reversed * 10 + (n % 10);
        n /= 10;
    }
    return reversed;
}

int BP(int A, int B, int P, int & count)
{
    cout << "BP: A: " << A << " | B: " << B << " | P: " << P << " | count: " << count << "\n"; 
    if (A == 0 && B == 0)
    {
        cout << "sprawdzam: " << P << "\n";
        if (isPrime(rev(P)))
        {
            ++count;
            cout << count << ": " << rev(P) << "\n";
        }
        return -1;
    }

    else
    {
        if (A > 0)
            BP(A / 10, B, P * 10 + (A % 10), count);

        if (B > 0)
            BP(A, B / 10, P * 10 + (B % 10), count);
    }
    return count;
}

int main()
{
    int A = 10, B = 9;
    int ile = 0;
    cout << BP(A, B, 0, ile) << "\n";
    //cout << isPrime(75123) << "\n";
    //cout << rev(32157) << "\n";
    return 0;
}
