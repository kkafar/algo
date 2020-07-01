#include <iostream>
using namespace std;

typedef long long ll; 
int l;

/// FUNKCJA POTĘGUJĄCA (POTĘGOWANIE SZYBKIE)
/*
	korzystamy z własnośći: 
	a^p = ( a ^ (p/2) )^2 jeśli 2|p; 
	a^p = ( a ^ (p/2) )^2 * a jeśli 2 nie dzieli p; 
*/
/// =============================
ll power(int a, int p)	// a - podstawa potęgi, p wykładnik. 
{
	if (p == 0) return 1; 
	
	ll result = a;
	// dopóki wykładnik jest większy od 1;
	while (p > 1) 
	{
		// podnosimy do kwadratu
		result *= result;

		// zliczamy operacje mnożenia
		++l;

		// jeżeli wykładnik jest nieparzysty to mnożymy result przez podstawę potęgi
		if (p & 1)
		{
			result *= a; 

			// zliczamy operacje mnożenia
			++l;
		} 


		// wykładnik dzielimy przez 2; 
		p >>= 1; 
	} 

	return result;
}
/// =============================

int main()
{
	int a, p, z;
	cin >> z;
	for (int i = 0; i < z; ++i)
	{
		cin >> a >> p;
		cout << power(a, p) << "\n";
		cout << "liczba mnozen: " << l << "\n";
		l = 0;
	}

	return 0; 
}
