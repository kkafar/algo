/* 
	<Wyszukiwanie ścieżki w drzewie binarnym  od zadanego węzła do korzenia. 
*/


#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std; 

template<class C>
void wyswietl_drzewo(C * T, int rozmiar)
{
	int poziom  = 1, licznik = 1; 
	for (int i = 1; i <= rozmiar; ++i)
	{
		cout << setw(4) << T[i] << " ";
		if (licznik == poziom)
		{
			licznik = 0; 
			poziom <<= 1; 
			cout << "\n";
		}
		++licznik;
	}
}

void sciezka(int * T, int rozmiar, int w)
{
	// to wyświetla mi ścieżkę od tyłu 
	while (w >= 1)
	{
		cout << w << " ";
		w /= 2;
	}
}


int main()
{
	srand(time(NULL));

	int l_elementow, w;

	cin >> l_elementow;

	int * T = new int[l_elementow + 1];

	for (int i = 1; i <= l_elementow; ++i)
		T[i] = rand() % 1000;

	wyswietl_drzewo(T, l_elementow);


	cin >> w; 

	sciezka(T, l_elementow, w);


	delete[] T;
	return 0;
}


