// https://pl.spoj.com/problems/PRZEDSZK/
#include <iostream>
 
using namespace std;
//co prawda przedszkolanka, ale sprowadza sie do wyznaczenia NWW(a,b)
// a wiec najpierw funkcja testowa (jak wyznaczyc NWW)
int nww(int a, int b)    // podobno (a*b)/NWD(a,b) = NWW(a,b)
{
    int modulo, a2 = a, b2 = b;
    while (b2 != 0) {                   //petla liczaca nwd, (a = nwd)
        modulo = a2%b2;
        a2 = b2;
        b2 = modulo;
    }
    return (a*b)/a2;            // zwroc NWW(a,b)
 
}
 
int main()
{
    short testy;
    cin >> testy;
    int gr1[testy], gr2[testy];
    for (int i = 0; i < testy; ++i) {
        cin >> gr1[i] >> gr2[i];
    }
    for (int i = 0; i < testy; ++i) {
        cout << nww(gr1[i], gr2[i]) << endl;
    }
 
    return 0;
}
