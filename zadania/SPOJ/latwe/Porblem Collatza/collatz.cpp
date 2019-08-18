//https://pl.spoj.com/problems/PTCLTZ/
#include <iostream>
 
using namespace std;
 
int main()
{
	int x_0, testy, licznik;
 
	cin >> testy; 
 
	for (int i = 0; i < testy; ++i)
	{
		cin >> x_0;
		licznik = 0; 
 
		while (x_0 != 1)
		{
			if (x_0 % 2)
				x_0 = 3 * x_0 + 1; 
			else
				x_0 /= 2;
 
			++licznik;
		}
 
		cout << licznik << "\n";
	}
	return 0;
 
} 
