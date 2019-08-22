/* WYZNACZANIE N-TEJ LICZBY FIBONNACIEGO */
// z wykorzystaniem dzialania na macierzach (szybkiego potegowania macierzy)
/*	 
	Jezeli przez f(n) (n >= 1) oznaczymy n-ta liczbe fibonnaciego to:
	Macierz 1 1 podniesiona do n-tej potegi wyglada nastepujaco: f(n+1) f(n)
		  1 0									f(n)   f(n-1)
	(na pewno w komorce [0][0] mamy f(n + 1)
		 
*/

#include <iostream>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; ++i)
#define foreach(i, a, b) for (int i = a; i <= b; ++i)

ll fib(int n)
{
	if (n < 1) return -1;
	// aby otrzymac n-ta liczbe z ciagu wystarczy podniesc macierz do (n-1)
	int expo = n - 1; 
	// tworzymy macierz Q[2][2]. Reprezentacja poprzez osobne zmienne dla szybszego dzialania
	// tworzymy tez macierz jednostkowa I[2], wykorzystywana do mnozenia oraz macierz 
	// pomocnicza P[2][2] do ktorej bedziemy tymczasowo zapisywac rezultaty dzialan
	ll Q11, Q12, Q21, Q22, I11, I12, I21, I22, P11, P12, P21, P22;
	// inicjujemy macierze odpowidnimi wartosciami 
	Q11 = Q12 = Q21 = I11 = I22 = 1; Q22 = I12 = I21 = 0;
	
	// dopoki wykladnik nie jest zerowy
	while (expo)
	{
		// jezeli najmlodszy bit wykladnika jest jedynka
		if (expo & 1)
		{
			// to I = I * Q
			// czyli najpierw P = I * Q, a potem przepisujemy zawartosc P do I
			P11 = I11 * Q11 + I12 * Q21;
			P12 = I11 * Q12 + I12 * Q22;
			P21 = I21 * Q11 + I22 * Q21;
			P22 = I21 * Q12 + I22 * Q22;
			
			I11 = P11; I12 = P12; I21 = P21; I22 = P22;
		}
		// przsuwamy bity wykladnika o raz w prawo
		expo >>= 1;
		// jezeli wykladnik sie wyzerowal to oznacza ze nie ma juz zadnych mnozen 
		// do wykonania i mozemy przerwac petle
		if (!expo) break;
		// w innym przypadku podnosimy do kwadratu macierz I 
		// bo przez nia mnozywmy macierz P
		P11 = Q11 * Q11 + Q12 * Q21;
		P12 = Q11 * Q12 + Q12 * Q22;
		P21 = Q21 * Q11 + Q22 * Q21;
		P22 = Q21 * Q12 + Q22 * Q22;
		
		Q11 = P11; Q12 = P12; Q21 = P21; Q22 = P22;
	}
	// po wykonaniu petli w macierzy I, na pozycji [1][1] (indeksowanie od 1) powinnismy 
	// miec f(n)
	return I11;
}

int main() {
	int n; 
	cin >> n;
	foreach(i, 1, n)
	{
		cout << "f(" << i << ") == " << fib(i) << "\n";
	}
	return 0;
}
