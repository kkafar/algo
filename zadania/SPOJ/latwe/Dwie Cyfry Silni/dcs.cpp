// https://pl.spoj.com/problems/FCTRL3/
#include <iostream>
using namespace std;
 
int main() {
    int D, silnia;
    cin >> D;
    int n[D];
    for (int i = 0; i < D; ++i) {
        cin >> n[i];
    }
 
    for (int i = 0; i < D; ++i) {
        if (n[i] >= 10) {
            cout << 0 << " " << 0 << endl;
            continue;
        }
 
        silnia = 1;
        for (int j = 1; j <= n[i]; ++j) {
            silnia = silnia * j;
        }
        int j, d;
        j = silnia%10;
        d = ((silnia-j)/10)%10;
        cout << d << " " << j << endl;
    }
	return 0;
}  
