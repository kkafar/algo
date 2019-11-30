/*
Zadanie 2.2b (2017/18) Kartkówka
Dana jest tablica int t[9], w której należy umieścić liczby od 1 do 9 tak, aby były spełnione
warunki:
1) wartości na sąsiednich polach tablicy muszą się różnić co najmniej o 2
2) liczby pierwsze nie mogą zajmować sąsiednich pól tablicy
Wartość 1 została już umieszczona na pierwszym miejscu (pod indeksem 0). Proszę napisać
program, który wypisuje wszystkie poprawne rozmieszczenia liczb w tablicy.
Nie mogę znaleźć błędu! generowane jest tylko jedno ustawienie, chyba że faktycznie innego nie ma
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 9;
int T[9];
int digit[8] = {2, 3, 4, 5, 6, 7, 8, 9};

void printTab(int T[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << T[i] << " ";
    
    cout << "\n";
}

unsigned int Abs(int x)
{
    return ((x < 0) ? (-x) : (x));
}

bool isPrime(int n)
{
    if (n == 2 || n == 3 || n == 5 || n == 7)
        return true;

    else 
        return false;
}

 bool condition(int T[N], int idx, int n)
 {
    if ( (Abs(T[idx-1] - n) < 2) || ( isPrime(T[idx-1]) && isPrime(n) ) )
        return false;

    else 
        return true;
 }

 void func(int T[N], int idx, int digit[8], int n)
 {
    //dane wywołania
    //cout << "func: idx: " << idx << " | n: " << n << "\n";


    // brzydko, ale nie mam czasu myśleć :D
    if (idx != 0)
    {
        T[idx] = n;
        // bo zabrałem n ze zbioru
        digit[n-2] = 0; 
    }

    //cout << "stany tablic: \nT[]: ";
    //printTab(T, N);
   // cout << "digit[]: ";
    //printTab(digit, 8);
    if (idx == N-1)
    {
        //cout << "TUTAJ\n";
        printTab(T, N);
        T[idx] = 0;
        digit[n-2] = n;
        return;
        
    }

    for (int i = 0; i < 8; ++i)
    {
        if (digit[i] != 0 && condition(T, idx + 1, i + 2))
            func(T, idx + 1, digit, i + 2);
    }

    // TEGO BRAKOWAŁO - uzupełnianie tablicy o zużytą liczbę przy wychodzieniu z instancji 
    digit[n-2] = n;
 }

int main()
{
    T[0] = 1;
    func(T, 0, digit, 1); 
    return 0;
}
