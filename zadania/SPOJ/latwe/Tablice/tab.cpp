#include <iostream>
using namespace std;
 
int main() {
	
    short testy;                                          //ile bedzie zestawow testowych
    cin >> testy;
    int n;                                                // ile liczb bedzie liczyl kazdy zestaw
    for (int i = 0; i < testy; ++i) {
        cin >> n;
        int m[n];                                         //zestaw
        for (int j = 0; j < n; ++j) {                     // wczytanie zestawu
            cin >> m[j];
        }
        for (int k = n-1; k >= 0; --k) {                   // wysietlenie w odwrotnej kolejnosci
            cout << m[k] << " ";
        }
        cout << endl;
    }
 
	return 0;
} 
