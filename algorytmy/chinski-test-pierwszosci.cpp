/* 
	Chiński test pierwszości 
	jest to algorytm PROPABILISTYCZNY oceniający czy podana liczba jest pierwsza

	Korzystamy z następującego twierdzenia 

	Jeżeli p jest naturanlne ∧ p > 1 ∧  2^p mod p != 2 
	to
	p jest liczbą złożoną. 

	Zatem jeżeli 2^p mod p == 2, to jest wysokie prawdopodobieństwo że p jest liczbą pierwszą (0,002% szansy na to że p jest liczbą "pseudopierwszą" dzielącą 2^p - 2).

	Algorytm nie daje prawidłowego rezutlatu także dla np. p == 2,
    gdyż 2^2 mod 2 == 0 (aby liczba była uznana za pierwszą to musi wyjść 2)
    Można by zrobić osobne obsługiwanie tego szczególnego przypadku. 
    Albo zmienić sprawdzanie warunku na 2^p mod p = 2 ∨ 2^p mod p = (p - 2)
*/

#include <iostream>
using namespace std;


long long power_mod(int a, int p, int q)
{
	long long result = 1; 
	int remainder = a; 

	while (p)
	{
		if (p & 1) result = (result * remainder) % q;

		remainder = (remainder * remainder) % q; 
		p >>= 1;
	}

	return result;
}

int main()
{
	int a, p, q, z, r;

	cin >> z;

	for (int i = 0; i < z; ++i)
	{
		cin >> p;
		if (p == 2)
			cout << "Pierwsza" << "\n";
		else
		{
			cout << ((power_mod(2, p, p) == 2) ? "Prawdopodobnie pierwsza" : "Zlozona") << "\n";
		}

	}
	return 0; 
}
