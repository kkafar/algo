/*
Zadanie 2.1a (2017/2018)
Dana jest tablica t[N][N] reprezentująca szachownicę, wypełniona liczbami naturalnymi. na
szachownicy znajdują się dwie wieże. Proszę napisać funkcję, która odpowiada na pytanie: czy
istnieje ruch wieży zwiększający sumę liczb na “szachowanych” przez wieże polach? Do funkcji
należy przekazać tablicę oraz położenia dwóch wież, funkcja powinna zwrócić wartość logiczną.
Uwagi: zakładamy, że wieża szachuje cały wiersz i kolumnę z wyłączeniem pola, na którym stoi.
N to globalny const int.
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 1000;


// tower 1: t[x1][y1]
// tower 2: t[x2][y2]

int get_fields_sum(int t[N][N], int x1, int y1, int x2, int y2)
{
    int sum = 0;
    if (x1 != x2 && y1 != y2)
    {
        for (int i = 0; i < N; i++)
            sum += t[x1][i] + t[x2][i] + t[i][y1] + t[i][y2];

        sum = sum - (t[x1][y1] + t[x2][y2] + t[x1][y2] + t[x2][y1]);
    }
    else if (x1 == x2)
    {
        for (int i = 0; i < N; i++)
            sum += t[i][y1] + t[i][y2] + t[x1][i];

        sum = sum - (t[x1][y1] * 2 + t[x2][y2] * 2);
    }
    else if (y1 == y2)
    {
        for (int i = 0; i < N; i++)
            sum += t[x1][i] + t[x2][i] + t[i][y1];

        sum = sum - (t[x1][y1] * 2 + t[x2][y2] * 2);
    }
    else
        sum = -1;

    return sum;
}

bool move_towers(int t[N][N], int x1, int y1, int x2, int y2)
{
    int default_sum = get_fields_sum(t, x1, y1, x2, y2);
    bool exists_better = false;

    if (x1 != x2 && y1 != y2)
    {
        for (int i = 0; i < N && !exists_better; i++)
        {
            // tower 1, move row (vertical)
            if (get_fields_sum(t, i, y1, x2, y2) > default_sum)
                exists_better = true;

            // tower 1, move column (horizontal)
            else if (get_fields_sum(t, x1, i, x2, y2) > default_sum)
                exists_better = true;

            // tower 2, move row (vertical)
            else if (get_fields_sum(t, x1, y1, i, y2) > default_sum)
                exists_better = true;

            // tower 2, move column (horizontal)
            else if (get_fields_sum(t, x1, y1, x1, i) > default_sum)
                exists_better = true;
        }
    }
    else if (x1 == x2)
    {
        // move rows (vertical) for both towers
        for (int i = 0; i < N && !exists_better; i++)
        {
            if (get_fields_sum(t, i, y1, x2, y2) > default_sum)
                exists_better = true;
            else if (get_fields_sum(t, x1, y1, i, y2) > default_sum)
                exists_better = true;
        }

        if (y1 < y2)  // tower 1 ... tower 2
        {
            for (int i = 0; i < y2 && !exists_better; i++)
                if (get_fields_sum(t, x1, i, x2, y2) > default_sum)
                    exists_better = true;
        }
        else  // tower 2 ... tower 1
        {
            for (int i = N - 1; i > y1 && !exists_better; i--)
                if (get_fields_sum(t, x1, y1, x2, i) > default_sum)
                    exists_better = true;
        }
    }
    else // y1 == y2
    {
        // move first tower - column
        for (int i = 0; i < N && !exists_better; i++)
        {
            // move columns (horizontal) for both towers
            for (int i = 0; i < N && !exists_better; i++)
            {
                if (get_fields_sum(t, x1, i, x2, y2) > default_sum)
                    exists_better = true;
                else if (get_fields_sum(t, x1, y1, x2, i) > default_sum)
                    exists_better = true;
            }
        }

        if (x1 < x2)  // (vertical) tower 1 ... tower 2
        {
            for (int i = 0; i < x2 && !exists_better; i++)
                if (get_fields_sum(t, i, y1, x2, y2) > default_sum)
                    exists_better = true;
        }
        else // (vertical) tower 2 ... tower 1
        {
            for (int i = N - 1; i > x1; i--)
                if (get_fields_sum(t, x1, y1, i, y2) > default_sum) 
                    exists_better = true;
        }
    }
    return exists_better;
}
