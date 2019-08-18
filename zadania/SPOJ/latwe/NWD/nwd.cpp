#include <iostream>
 
using namespace std;
// naglowek funkcji
int nwd(int a, int b);
// ---------------
int main() {
	short t;																	// liczba zestawow testowych
	cin >> t;
	int *a, *b;																	// weeee, pierwszy raz robie to przez wskaznik :)
	a = new int[t];																// -----------------------------------------------
	b = new int[t];
	for (int i = 0; i < t; ++i) {
		cin >> a[i] >> b[i];
		nwd(a[i], b[i]);
	}
}
 
int nwd(int a, int b) {
	do {
		int reszta;
		reszta = a % b;
		a = b;
		b = reszta;
	} while (b);
	cout << a << endl;
	return 0;
} 
