#include <iostream>

typedef long long ll;

ll silnia(int n)
{
	if (n <= 1) return 1; 
	else return ( n * silnia(n - 1)); 
}

int main()
{
	int n, k; 
	std::cout << "Podaj n i k (n ≥ k ≥ 0)" << "\n";
	std::cin >> n >> k; 

	ll wynik = 1; 

	for (int i = n; i > n - k; --i)
		wynik *= i; 

	std::cout << wynik / silnia(k) << "\n";

	return 0;
}
