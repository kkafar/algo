#include <iostream>

using namespace std;

long long silnia(int n)
{
    if ( n == 1 ) return 1;
    else if (n == 0) return 1;

    return (n * silnia ( n - 1 ));

}

int main()
{
    int a;

    cin >> a;

    cout << silnia(a) << endl;
    return 0;
}
