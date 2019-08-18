#include <iostream>
using namespace std;
 
int main()
{
    int *t = new int, *n = new int;
 
    cin >> *t;
    for (int i = 0; i < *t; ++i) {
        cin >> *n;
        int *tab = new int[*n], *tab2 = new int[*n];
 
        cin >> tab2[*n-1];
        for (int j = 1; j < *n; ++j) {
            cin >> tab[j];
        }
 
        for (int j = 0; j < ((*n)-1); ++j) {
            tab2[j] = tab[j+1];
        }
        
 
        for (int j = 0; j < *n; ++j) {
            cout << tab2[j] << " ";
        }
        cout << endl;
        delete [] tab;
        delete [] tab2;
    }
    return 0;
} 
