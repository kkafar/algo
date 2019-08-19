/* ALGORYTM POTĘGOWANIA MACIERZY */
/*
	Opis działania algorytmu: https://eduinf.waw.pl/inf/alg/001_search/0075.ph
*/
#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;

#define f(i, a) for (int i = 0; i < a; ++i)

// procedura przepisująca macierz B do macierzy A
void rewrite(int ** A, int ** B,  int n)
{
	f(i, n)
	{
		f(j, n)
		{
			A[i][j] = B[i][j];
		}
	}
}

// procedura mnożąca 2 macierze i zapisująca wynik w macierzy wynikowej W (n x n)
void multiply(int ** A, int ** B, int n, int ** W)
{
	int s = 0;
	f(i, n)
	{
		f(j, n)
		{
			s = 0;
			f(k, n) s += A[i][k] * B[k][j];
			W[i][j] = s;
		}
	}
}

// procedura podnosząca daną macierz kwadratową do zadanej potęgi 
void power(int ** A, int n, int exp)
{
	// tworzymy macierze pomocnicze, W, i P;
	int ** W = new int* [n], ** P = new int * [n];

	f(i, n)
	{
		W[i] = new int[n];	
		P[i] = new int[n];
	}

	// z macierzy W robimy macierz jednostkowa
	f(i, n)
	{
		f(j, n) W[i][j] = 0;
		W[i][i] = 1;
	}

	/* WŁAŚCIWA CZĘŚĆ ALGORYTMU */
	/// =========================================
	// dopóki wykładnik nie jest zerowy
	while (exp)
	{
		// jeżeli najmłodszy bit wykładnika jest jedynką 
		if (exp & 1) 
		{
			// to wykonujemy operację W = W x A
			//--------
			multiply(W, A, n, P);
			rewrite(W, P, n);
			//--------
		}
		// przesuwamy bity wykładnika o 1 w prawo
		exp >>= 1;
		// jeżeli wykładnik jest zerowy to przeywamy dziłanie pętli, bo to oznacza, że 
		// w macierzy W mamy już wynik :) 
		if (!exp) break;

		// w innym przypadku oznacza to że w następnym kroku będziemy mnożyć przez A^2. Zatem podnosimy macież A do kwadratu 
		multiply(A, A, n, P);
		rewrite(A, P, n);
	}
	// po wyjściu z pętli właściwy wynik mamy w macierzy W, zatem należy go jeszcze przepisać do macierzy A
	rewrite(A, W, n);
	/// =========================================


	f(i, n) { delete[] W[i]; delete[] P[i];}
	delete[] W; delete[] P;
}

void printMatrix(int ** M, int n, const string& s = "")
{
	cout << "\n" << s << "\n";
	f(i, n)
	{
		f(j, n)
		{
			cout << setw(5) << M[i][j] << " ";
		}
		cout << "\n";
	}
	
}

int main()
{
	srand(time(NULL));
	// n - stopień macierzy
	int n, exp;

	cin >> n >> exp;

	/* TWORZYMY MACIERZ KWADRATOWĄ */
	// bo przecież tylko taką możęmy potęgować
	/// =========================================
	int ** M  = new int *[n];
	f(i, n)
	{
		M[i] = new int[n];
		f(j, n) M[i][j] = rand() % 10;
	}
	/// =========================================

	printMatrix(M, n, "M");

	power(M, n, exp);

	printMatrix(M, n, "M");


	f(i, n) delete[] M[i];
	delete[] M;

	return 0;
}
