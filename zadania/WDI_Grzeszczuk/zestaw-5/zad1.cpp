#include <iostream>
using namespace std;


// METODY
// ==================================
/*
* Metoda zwracająca największy wspólny dzielnik liczb a i b 
* z wykorzystaniem arytmetyki modulo
*/
int nwd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a >= b) a %= b;
        else        b %= a;
    }
    // chcemy zwrócić niezerową, ale skoro druga jest zerem, to możemy zwrócić ich sumę
    // i się nie zastanawiać która jest która.
    return a + b;
}

/*
*   Metoda zwracająca najmniejszą wspólną wielokrotność 2 liczb.
*   Nie wiem czy istnieje fajniejszy algorytm (szybszy, z mniejszym ryzkiem wyjścia poza zakres int)
*/
int nww(int a, int b)
{
    // w takiej kolejności bo chcemy maksymalnie zminimalizować szanse wyjscia poza zkares typu int 
    return a / nwd(a, b) * b;
}
// ==================================

struct ulamek
{
    // POLA
    // ==================================
    // l - licznik, m - mianownik
    int l = 0, m = 1;
    // ==================================

    // METODY
    // ==================================
    void fpow(int exp)
    {
        while (!exp)
            // TU KONTUNUUJEMY
    }
    // ==================================
};
/*
*   operator +, przeciążony tutaj, bo w structurze operator nie może przyjmować podwójnych argumentów? Przynajmniej tak 
*   interpretuje błędy wywalane przez kompilator. 
*   zwracamy ulamek względnie pierwszy!!!
*/
ulamek operator + (ulamek a, ulamek b)
{
    int nw = nww(a.m, b.m);
    ulamek returnVal; 
    returnVal.l = a.l * nw / a.m + b.l * nw / b.m;
    returnVal.m = nw;
    return returnVal;
}
ulamek operator - (ulamek a, ulamek b)
{
    int nw = nww(a.m, b.m);
    ulamek returnVal;
    returnVal.l = a.l * nw / a.m - b.l * nw / b.m;
    returnVal.m = nw;
    return returnVal;
}
ulamek operator * (ulamek a, ulamek b)
{
    ulamek returnVal;
    returnVal.l = a.l * b.l;
    returnVal.m = a.m * b.m;
    // jeszcze potrzebujemy skrócić ten ułamek
    int nw = nwd(returnVal.l, returnVal.m);
    returnVal.l = returnVal.l / nw;
    returnVal.m = returnVal.m / nw;
    return returnVal;
}
ulamek operator / (ulamek a, ulamek b)
{
    ulamek returnVal;
    returnVal.l = a.l * b.m;
    returnVal.m = a.m * b.l;
    int nw = nwd(returnVal.l, returnVal.m);
    returnVal.l = returnVal.l / nw;
    returnVal.m = returnVal.m / nw;
    return returnVal;

}
int main()
{
    ulamek a, b; 
    cout << "a = " << a.l << "/" << a.m << "\n";
    cout << "b = " << b.l << "/" << b.m << "\n";

    cout << "a: ";
    cin >> a.l >> a.m;
    cout << "b: ";
    cin >> b.l >> b.m;

    cout << "a = " << a.l << "/" << a.m << "\n";
    cout << "b = " << b.l << "/" << b.m << "\n";

    a = a + b;
    cout << "a+b = " << a.l << "/" << a.m << "\n";
    return 0;
}
