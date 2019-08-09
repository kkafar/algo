// https://pl.spoj.com/problems/PA05_POT/
#include <iostream>
using namespace std;
 
int main() {
	
    short ile;
    cin >> ile;
    int a[ile], b[ile];
    for (int i = 0; i < ile; ++i) {
        cin >> a[i] >> b[i];
    }
 
    int c;
    for (int j = 0; j < ile; ++j) {
        c = a[j]%10;
        if (c == 0) {
            cout << 0 << endl;
            continue;
        } else if (c == 5 || c == 6 || b[j] == 1) {
            cout << c << endl;
            continue;
        }
 
        int d = c, okres = 0;
        do {
            d = d * c;
            ++okres;
        }  while (d%10 != c);
 
        d = 1;
        for (int l = 0; l < b[j]%okres; ++l) {
            d = d * c;
        }
        cout << d%10 << endl;
 
    }
	return 0;
} 
