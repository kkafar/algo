#include <iostream>
using namespace std;
 
int main() {
	inz z; 
	cin >> z;
	for (int i = 0; i < z; ++i) 
	{
		long long a, k, q, wynik, c; 
		cin >> a >> k >> q;
		c = a; 
		wynik = 1;
		while (k != 0)
		{
			if (k % 2 == 1)
			{
				wynik = (wynik * c) % q;
			}
			k /= 2;
			c = (c*c) % q;
		}
		cout << wynik << endl;
	}
	return 0
}
