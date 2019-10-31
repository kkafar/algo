/*
 *	ZESTAW 3
 * 	ZADANIE 3
 * 	SITO ERASTOTENESA 
 * 	 
 *
 *	ZŁ. PAMIĘCIOWA: N/2
 * 
 * 	Korzystamy z faktu, że żadna liczba pierwsza > 2 nie jest
 * parzysta, zatem nie potrzebujemy wykreślać żadnych wielokrotności 
 * liczb parzystych, ani parzystych wielokrotności liczb 
 * nieparzystych
*/

#include <iostream>
using namespace std;

int main()
{
	/// dostajemy na wejście liczbę n, zakładam, że n >= 2
	/// potrzebujemy wyznaczyć wszystkie
	/// liczby pierwsze w przedziale domkniętym [1…n] 
	
	int n, currentNumb, j; 
	
	cin >> n;
	
	cout << "2 ";
	if (n == 2) return 0;
	// dodajemy 1 do rozmiaru żeby móc wygodnie numerować komórki od 1
	bool * isPrime = new bool [n/2 + 1];
	
	// na starcie zakładamy o wszystkich że są pierwsze
	for (int i = 1; i <= n/2; ++i) isPrime[i] = true;
	
	
	
	// jeżeli currentNumb^2 == n to znaczy że n na pewno nie jest pierwsza
	currentNumb = 3;
	for (int i = 1; currentNumb * currentNumb < n; ++i, currentNumb += 2)
	{
		if (isPrime[i])
		{
			// wykreślamy wszystkie jej nieparzyste wielokrotności począwszy
			// od kwadratu danej liczby (wszystkie mniejsze zostały wykreślone wcześniej
			j = currentNumb;
			while (currentNumb * j < n)
			{
				isPrime[(currentNumb * j) / 2] = false;
				j += 2;
			}
		}
	}
	
	// wyświetlamy rezultaty pracy algorytmu
	for (int i = 1; i < n/2; ++i)
		if (isPrime[i])
			cout << 2 * i + 1 << " ";
	cout << "\n";
	
	delete[] isPrime;
	return 0;
}
