/* ALGORYTM MNOŻENIA MACIERZY (MACIERZ PRZEZ MACIERZ) */ 

#include <iostream>
#include <iomanip>
#include <time.h> // do generowania losowej zawartości macierzy
#include <string>
using namespace std;

#define foreach(i, a, b) for (int i = a; i <= b; ++i)

void printMatrix(int ** M, int w, int k, const string& s = "")
{
	cout << "\n" << s << "\n";
	foreach(i, 0, w - 1)
	{
		foreach(j, 0, k - 1)
		{
			cout << setw(5) << M[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	srand(time(NULL));

	int w1, k1, k2, wynik; 
	
	cout << "Podaj dane w formacie: liczba_wierszy_macierzy_1 liczba_kolumn_macierzy_1 liczba_kolumn_macierzy_2\n";
	// (liczba wierszy macierzy nr 2 jest taka sama jak liczba kolumn macierzy 1, dlatego jej nie pobieramy)

	cin >> w1 >> k1 >> k2;

	/* Tworzymy macierze (jako tablice 2 wymiarowe) */
	/// ===============================================
	// najpierw tworzymy tablicę wskaźników, z których każdy będzie tablicą intów (reprezentując tym samym 
	// jeden wiersz macierzy)
	int ** M1 = new int * [w1];
	int ** M2 = new int * [k1];
	// teraz tworzymy macierze 
	// M1 (w1 x k1)
	foreach(i, 0, w1 - 1)
	{
		// tworzymy i-ty wiersz, mający tyle elementów ile kolumn liczy macierz
		M1[i] = new int[k1];
		// od razu przypisujemy jakieś losowe liczby całkowite z przedziału [0…50);
		foreach(j, 0, k1 - 1) M1[i][j] = rand() % 50;

	} 
	// tak samo dla macierzy M2
	// M2 (k1 x k2)
	foreach(i, 0, k1 - 1)
	{
		M2[i] = new int[k2];
		foreach(j, 0, k2 - 1) M2[i][j] = rand() % 50;
	}
	/// ===============================================

	/* WYŚWIETLANIE ZAWARTOŚCI MACIERZY PRZED MNOŻENIEM */ 
	/// ===============================================
	cout << "ZAWARTOSC MACIERZY PRZED MNOZENIEM\n";
	printMatrix(M1, w1, k1, "M1");
	printMatrix(M2, k1, k2, "M2");
	/// ===============================================	

	/* TWORZYMY MACIERZ WYNIKOWĄ W (w1 x k2)*/
	/// ===============================================
	int ** W = new int * [w1];
	foreach(i, 0, w1 - 1) W[i] = new int[k2];
	/// ===============================================

	/* MNOŻENIE MACIERZY M1 x M2 */
	/// ===============================================
	// iterator i biegnie po wierszach macierzy W
	foreach(i, 0, w1 - 1)
	{
		// iterator j biegnie po kolumnach macierzy W
		foreach(j, 0, k2 - 1)
		{
			wynik = 0; 
			foreach(k, 0, k1 - 1) wynik += M1[i][k] + M2[k][j];
			W[i][j] = wynik;
		}
	}
	/// ===============================================

	/* WYŚWIETLANIE MACIERZY WYNIKOWEJ W (w1 x k2) */
	/// ===============================================
	cout << "\nMACIERZ WYNIKOWA W " << w1 << "x" << k2;
	printMatrix(W, w1, k2);
	/// ===============================================	 

	/* ZWALNIANIE PAMIĘCI ZAREZERWOWANEJ NA MACIERZE */
	/// ===============================================
	foreach(i, 0, w1 - 1) { delete[] M1[i]; delete[] W[i]; }
	foreach(i, 0, k1 - 1) delete[] M2[i];
	delete[] M1; delete[] M2; delete[] W;
	/// ===============================================

	return 0;
}
