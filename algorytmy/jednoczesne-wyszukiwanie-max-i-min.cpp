/* Jednoczesne znajdywanie max i min w danym, n-elementowym zbiorze liczbowym 
	O(n), ale mniej porównań niż normalne wyszukiwanie liniowe
*/ 

#include <iostream>
using namespace std; 

#define PINF 100000
#define MINF -100000

int main()
{
	/* DEFINIOWANIE ZMIENNYCH */
	/// ============================ 
	// liczba elementów w zbiorze; wartość minimalna = +INF, wartość maksymalna = -INF
	int n, minv = PINF, maxv = MINF;
	/// ============================

	cin >> n; 

	// rezerwacja pamięci na n-elementową tablicę liczb
	// ważne jest dla nas, aby tablica miała parzystą liczbę elementów, więc jeżeli tak nie jest, 
	// to po prostu duplikujemy potem ostatni element 
	// zawsze na sztywno, rezerwujemy jedną komórkę więcej, jeżeli n jest parzyste
	// to po prostu jej nie wykorzystujemy
	// pewnie są inne, bardziej eleganckie rozwiązania, no cóż :D 
	int * T = new int[n + 1]; 

	// wczytywanie tablicy liczb
	for (int i = 0; i < n; ++i)
		cin >> T[i]; 

	// jeżeli n było nieparzyste to duplikujemy ostatni element
	if (n % 2 == 1)
		T[n] = T[n - 1]; 

	/* WYSZUKIWANIE MIN I MAX */
	/// ============================
	// i < n, bo: 
	// 1. dla n parzystego, w ostaniej iteracji rozważona zostanie para (n - 2) i (n - 1)
	// a wtedy przecież z komórki n nie korzystamy
	// 2. dla n nieparzystego, w ostatniej iteracji zostanie rozważona para (n - 1) i n 
	// więc wszystko się zgadza. Warto o tym fakcie pamiętać.  
	for (int i = 0; i < n; i = i + 2)
	{
		// rozpatrujemy parę
		if (T[i] < T[i + 1])
		{
			if (T[i + 1] > maxv) maxv = T[i + 1];
			if (T[i] < minv) minv = T[i]; 
		}
		else
		{
			if (T[i + 1] < minv) minv = T[i + 1];
			if (T[i] > maxv) maxv = T[i];
		}
	}
	//po wynonaniu tej pętli powinniśmy mieć znalezione min i max zadanego zbioru 
	/// ============================ 

	/* WYŚWIETLANIE REZULTATÓW */
	/// ============================ 
	// najpierw wyświetlimy wyjściową tablicę liczb
	for (int i = 0; i < n; ++i)
		cout << T[i] << " "; 
	cout << "\n"; 
	cout << "MIN: " << minv << " | MAX: " << maxv << "\n";
	/// ============================ 

	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	/// ============================  
	delete[] T;
	/// ============================ 

	return 0;
}
