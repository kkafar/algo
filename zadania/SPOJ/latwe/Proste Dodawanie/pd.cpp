#include <iostream>
 
using namespace std;
 
int main() {
    short skladniki, testy; 
    int suma;
    cin >> testy;
 
    for (int j = 0; j < testy; ++j) {
        cin >> skladniki;
        int a[skladniki];
        suma = 0;
        for (int i = 0; i < skladniki; ++i) {
            cin >> a[i];
            suma += a[i];
        }
        cout << suma << endl;
    }
 
 
    return 0;
}
 
