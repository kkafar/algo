/* Porównianie czasów wykonywania algorytmów wyznaczających zadany wyraz ciągu fibonnaciego. 
	1. Metoda rekruencyjna. 
	2. Metoda dynamiczna
	3. Metoda z wykorzystaniem dzialania na macierzach 

	Przez f(n) (n >= 1) oznaczamy n-tą liczbę ciągu fibonnaciego
	Dla n ≤ 1 f(n) == -1 (umowne oznaczenie dla błędnego wejścia)

	Rezultaty są bardzo ciekawe. Algorytm rekurencyjny jest niezwykle wolny. 
	Bottom-up uchodzi, natomiast algorytm macierzowy ma czas wykonania bliski zeru dla n <= 45 (tylko do takich przetestowałem).

	Do metody 2 kojarzym mi się jeszcze pojęcie sumy prefixowo-sufixowej, mam coś na ten temat w zeszycie z JWO
*/

#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

typedef long long ll;
#define rep(i, a) for (int i = 0; i < a; ++i)
#define foreach(i, a, b) for (int i = a; i <= b; ++i)

/* Działanie tychfunkcji jest albo oczywiste, albo rozwiązanie wraz z pełnym komentarzem znajduje się na githubie */
/// ======================================
ll fib_r(int n)
{
	if (n < 1) return -1;
	if (n <= 2) return 1;
	else return (fib_r(n - 1) + fib_r(n - 2));
}

ll fib_bottom_up(int n)
{
	if (n < 1) return -1;
	ll F_n;
	ll * F = new ll[n + 1];
	F[0] = 0;
	F[1] = 1; 

	foreach(i, 2, n)
		F[i] = F[i - 1] + F[i - 2];

	F_n = F[n];

	delete[] F;
	return F_n;
}

ll fib_mtx(int n)
{
	if (n < 1) return -1;

	int expo = n - 1; 

	ll Q11, Q12, Q21, Q22, I11, I12, I21, I22, P11, P12, P21, P22;
	
	Q11 = Q12 = Q21 = I11 = I22 = 1; Q22 = I12 = I21 = 0;

	while (expo)
	{
		if (expo & 1) 
		{
			P11 = Q11 * I11 + Q12 * I21; 
			P12 = Q11 * I12 + Q12 * I22;
			P21 = Q21 * I11 + Q22 * I21;
			P22 = Q21 + I12 + Q22 * I22;

			I11 = P11; I12 = P12; I21 = P21; I22 = P22;
		}

		expo >>= 1;

		if (!expo) break;

		P11 = Q11 * Q11 + Q12 * Q21; 
		P12 = Q11 * Q12 + Q12 * Q22;
		P21 = Q21 * Q11 + Q22 * Q21;
		P22 = Q21 * Q12 + Q22 * Q22;

		Q11 = P11; Q12 = P12; Q21 = P21; Q22 = P22;	
	}
	return I11;
}
/// ======================================


int main()
{
	/*
	const int a = 20;
	cout << "Algorytm rekurencyjny: \n";
	rep(i, a)
	{
		cout << "f(" << i << ") == " << fib_r(i) << "\n";
	}

	cout << "Algorytm bottom up: \n";
	rep(i, a)
	{
		cout << "f(" << i << ") == " << fib_bottom_up(i) << "\n";
	}

	cout << "Algorytm macierzowy: \n";
	rep(i, a)
	{
		cout << "f(" << i << ") == " <<	fib_mtx(i) << "\n";
	}
	*/


	/* Porównywanie czasu działania algorytmów */ 
	/// ===============================================
	int n;
	ll result;
	clock_t t1, t2; 
	double dt;

	cin >> n;

	t1 = clock();
	result = fib_r(n);
	t2 = clock();

	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;

	cout << "ALGORYTM REKURENCYJNY\nCzas dzialania: " << setprecision(10) << setw(10) <<  dt << "   Wynik: " << result << "\n";

	t1 = clock();
	result = fib_bottom_up(n);
	t2 = clock();

	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;

	cout << "ALGORYTM BOTTOM UP\nCzas dzialania: " << setprecision(10) << setw(10) << dt << "   Wynik: " << result << "\n";
	
	t1 = clock();
	result = fib_mtx(n);
	t2 = clock();

	dt = (double)(t2 - t1) / CLOCKS_PER_SEC;

	cout << "ALGORYTM MACIERZOWY\nCzas dzialania: " << setprecision(10) << setw(10) << dt << "   Wynik: " << result << "\n";


	/// ===============================================

	return 0;
} 
