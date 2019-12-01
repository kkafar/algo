/*
Zadanie 1.2a kolos 2015 ad-wdi-kl-a, wtorek, 3 listopada 2015
2) Proszę napisać program, który wypełnia tablicę t[N] pseudolosowymi liczbami nieparzystymi z zakresu [1..99],
a następnie Wyznacza i wypisuje różnicę pomiędzy długością najdłuższego znajdującego się w niej ciągu
arytmetycznego o dodatniej różnicy, a długością najdłuższego ciągu arytmetycznego o ujemnej różnicy, przy
założeniu, że kolejnymi wyrazami ciągu są elementy tablicy o kolejnych indeksach.
*/

#include <iostream>
#include <time.h>
using namespace std;

#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define REP(i, a) for (int i = 0; i < a; ++i)

const int N = 15;
const int INF = 2000000000;

template<class C>
void printTab(C T[], int size)
{
    REP(i, size)
        cout << T[i] << " ";
    cout << "\n";
}

int main()
{
    srand(time(NULL));
    //int T[N], random;
    /*
    REP(i, N)
    {
        random = rand() % 99 + 1;
        if (random % 2 == 0)
            ++random;

        T[i] = random;
    }
    */
    int T[N] = {1, 2, 3, 5, 4, 3, 2, 1, 0, 4, 8, 12, 16, 20, 24};
    printTab(T, N);

    int posLeng = 1, negLeng = 1, maxPosLeng = 1, maxNegLeng = 1, oldDiff = INF;
    int newDiff = INF;

    newDiff = oldDiff = T[1] - T[0];

    //if (newDiff > 0) ++posLeng;
    //if (newDiff < 0) ++negLeng;

    FORU(i, 1, N-1)
    {
        cout << "iter: i: "<< i << " | T[i]: " << T[i] << " | T[i-1]: " << T[i-1] << " | posLeng: " << posLeng << " | negLeng: " << negLeng << " | maxPosLeng: " << maxPosLeng << " | maxNegLeng: " << maxNegLeng << "\n";

        newDiff = T[i] - T[i - 1];
        if (newDiff == oldDiff)
        {
            if (newDiff > 0) 
                ++posLeng;

            else if (newDiff < 0)
                ++negLeng;
        }

        else
        {
            if (posLeng > maxPosLeng)
                maxPosLeng = posLeng;

            if (negLeng > maxNegLeng)
                maxNegLeng = negLeng;

            oldDiff = newDiff;
            posLeng = 2; 
            negLeng = 2; 
        }
    }

    if (posLeng > maxPosLeng)
        maxPosLeng = posLeng;

    if (negLeng > maxNegLeng)
        maxNegLeng = negLeng;

    int DIFF = maxPosLeng - maxNegLeng;
    cout << DIFF << "\n";
    return 0;
}
