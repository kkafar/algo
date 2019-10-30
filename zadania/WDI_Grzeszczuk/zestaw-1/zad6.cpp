// 6. Napisać program rozwiązujący równanie x^x=2019 metodą bisekcji.
#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    double x = 5.0 / 2, E = 0.01, result = 0, l = 0, p = 5; 

    do
    {
        result = pow(x, x);

        if (result < 2019)
        {
            l = x; 
            x = (x + p) / 2;
        }

        else if (result > 2019)
        {
            p = x; 
            x = (x + l) / 2; 
        }

    } while (abs(result - 2019) >= E);

    cout << setprecision(10) <<  x << "\n";
    return 0;
}
