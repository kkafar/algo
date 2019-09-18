#include <iostream>
using namespace std;

typedef long long ll; 

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
    
		// jeżeli wykładnik jest nieparzysty to mnożymy result przez podstawę potęgi
		if (p & 1)
		{
			result *= a; 
		} 
    
		// wykładnik dzielimy przez 2; 
		p >>= 1; 
	} 

	return result;
}
/// =============================


// ogólnie zasada działania pokażemy na przykładzie :
/*
	5^7: 
	7 = (0111) = 2^2 + 2^1 + 2^0
	
	Zauważmy że 5^7 = 5^4 × 5^2 × 5^1
	Natomiast 4 = 2^2, 2 = 2^1, 1 = 2^0
	Zatem widzimy że musimy wymnożyć ze sobą takie potęgi liczby 5, których wykładniki 
	są równe wagom niezerowych bitów liczby siedem.
*/
long long power2(int a, int p) 
{
	// result - zmienna przechowująca wynik, przypisujemy na starcie 1 bo gdy p == 0, pętla się nie wykona
	// (a przecież chcemy zwrócić wtedy 1)
	// M - a ^ (waga rozważanego bitu wykładnika)
	long long result = 1, M = a;

	// dopóki wykładnik nie jest zerowy
	while (p)
	{
		// jeżeli najmłodszy bit wykładnika jest jedynką to dodajemy tą potęgę liczby a do jej rozkładu 
		if (p & 1) result *= M; 

		// a ^ (waga kolejnego bitu wykładnika)
		M *= M; 
		// przesuwamy bity wykładnika raz w prawo
		p >>= 1;
	}

	return result;
}

int main()
{
	int a, p, z;
	cin >> z;
	for (int i = 0; i < z; ++i)
	{
		cin >> a >> p;
		cout << power(a, p) << "\n";
		cout << power2(a, p) << "\n";
	}

	return 0; 
}
