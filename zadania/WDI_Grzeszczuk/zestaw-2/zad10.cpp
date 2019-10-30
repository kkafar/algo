//Napisać program, który oblicza pole figury pod wykresem funkcji y=1/x w przedziale
// 1 do k, metodą prostokątów.

#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int k, m;  
    cin >> k >> m; 


    double x = (double)(k-1) / (m);
    double S = 0.0;

    for (int i = 1; i <= m; ++i)
    {
        S += x * 1/(1 + i * x);
    }

    cout << "Na przedziale od " << 1 << " do " << k << ": ";
    cout << setprecision(20) << S << "\n";

    return 0;
}
