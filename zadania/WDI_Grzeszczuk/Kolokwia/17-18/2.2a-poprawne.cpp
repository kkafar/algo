/*
Zadanie 2.2a (2017/2018)
Dana jest tablica int t[9], w której należy umieścić liczby od 1 do 9 tak, aby były spełnione
warunki:
1) wartości na sąsiednich polach tablicy muszą się różnić co najmniej o 2
2) liczby pierwsze nie mogą zajmować sąsiednich pól tablicy
Wartość 1 została już umieszczona na pierwszym miejscu (pod indeksem 0). Proszę napisać
program, który wypisuje wszystkie poprawne rozmieszczenia liczb w tablicy.
*/

#include <iostream>
#include <string>
using namespace std;

int T[9];


bool is_prime(int x)
{
    if (x == 0 || x == 1)
        return false;
    
    bool prime = true;
    for (int i = 2; i * i <= x && prime; i++)
        if (x % i == 0)
            prime = false;

    return prime;
}


int diff(int a, int b)
{
    if (a > b)
        return a - b;
    else
        return b - a;
}

void place(int t[9], int curr_index, bool used_numbers[10])
{
    if (curr_index == 9)
    {
        for (int i = 0; i < 9; i++)
            cout << t[i];
        cout << "\n";
    }
    
    for (int i = 2; i < 10; i++)
    {
        if (!used_numbers[i] &&
            diff(t[curr_index - 1], i) >= 2)
        {
            bool prev_prime = is_prime(t[curr_index - 1]);
            bool curr_prime = is_prime(i);
            
            if (!(prev_prime && curr_prime))
            {
                used_numbers[i] = true;
                t[curr_index] = i;
                place(t, curr_index + 1, used_numbers);
            }
            
            used_numbers[i] = false;
        }
    }
}

void place_numbers()
{
    int t[9] = {0};
    t[0] = 1;
    
    bool used_numbers[10] = {false};
    used_numbers[1] = true;

    place(t, 1, used_numbers);
}

int main()
{

    T[0] = 1;
    place_numbers();
    return 0;
}
