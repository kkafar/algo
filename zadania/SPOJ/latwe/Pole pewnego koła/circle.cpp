    #include <iostream>
    #include <cmath>
    #include <iomanip>
    using namespace std;
    typedef long double ld;
    const double PI = 3.141592654;
 
    int main()
    {
        ld *r = new ld, *d = new ld, *h2 = new ld;
 
        cin >> *r >> *d;
 
        *h2 =  pow(*r, 2) - pow(*d/2, 2);
 
 
        cout.setf(ios::fixed);
        cout.precision(2);
        cout << PI * *h2;
 
        delete r; delete d; delete h2;
        return 0;
    }
 
