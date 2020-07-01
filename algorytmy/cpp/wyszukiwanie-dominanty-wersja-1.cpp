/*	
	Algortym wyszukujący dominantę w zbiorze liczbowym. 
	Wersja 1

	* Co gdy zbiór ma kilka wartości występujących tyle samo razy (najwięcej razy). Wszystkie są dominantami,
	czy zbiór wtedy nie ma dominanty
	** WSZYSTKIE SĄ DOMINANTAMI
	Zatem ten algorytm tego nie obsługuje. Jest poprawny tylko dla zbiorów z jedną dominantą. 
*/

#include <iostream>
#include <time.h> // do srand(...) i rand(), będziemy uzupełniać nimi tablice

using namespace std;

int main()
{
	srand(time(NULL));

	/* REZERWACJA PAMIĘCI I WEJŚCIE */
	/// ================================= 
	// minv i maxv ustawiamy na sztywno
	int l_elementow, minv = 1000000, maxv = -1000000, index;

	cin >> l_elementow;

	// l_elementow + 1, żeby móc zrealizować algorytm jednoczesnego wyszukiwania minimum i maksimum
	int * T = new int[l_elementow + 1];
	/// ================================= 

	/* UZUPEŁNAINIE TABLICY LOSOWYMI LICZBAMI*/
	/// =================================
	// z przedziału [0...1000)
	for (int i = 0; i < l_elementow; ++i) T[i] = rand() % 1000;  
	/// ================================= 

	/* WYSZUKIWANIE DOMINANTY */
	/// ================================= 
	// najpierw potrzebujemy znaleźć min i max w zbiorze, aby określić przedział 
	// w jakim zawierają się jego wartości, więc korzystamy z algorytmu jednoczesnego wyszukiwania
	// min i max
	// jeżeli liczba elementów zbioru jest nieparzysta to powielamy ostatni element
	if (l_elementow % 2)
		T[l_elementow] = T[l_elementow - 1];

	for (int i = 0; i < l_elementow; i = i + 2)
	{
		if (T[i] < T[i + 1])
		{
			if (T[i] < minv) minv = T[i];
			if (T[i + 1] > maxv) maxv = T[i + 1];
		}

		else 
		{
			if (T[i] > maxv) maxv = T[i];
			if (T[i + 1] < minv) minv = T[i + 1];
		}
	}
	// po wykonaniu tej pętli w zmiennym minv i maxv powinniśmy mieć właściwe wartości 
	// czyli odpowiednio minimalną i maksymalną wartość w zbiorze T.
	// teraz tworzymy tablicę liczników, zliczającą kolejne wartości. 
	int l_wartosci = maxv - minv + 1;
	int * L = new int[l_wartosci];
	// zerujemy tablicę zliczającą wartości;
	for (int i = 0; i < l_wartosci; ++i) L[i] = 0; 

	// zliczamy wystąpienia poszczególnych wartości
	for (int i = 0; i < l_elementow; ++i) ++L[T[i] - minv];

	// wyznaczamy liniowo najczęściej występujący element 	
	// wykorzystujemy wcześniejsze zmienne: 
	// maxv - ilość wystąpień najczęstszej wartości, 
	// index - indeks najczęstszej wartości
	maxv = L[0]; index = 0; 
	for (int i = 1; i < l_wartosci; ++i)
	{
		// jeżeli wartość (i + minv), której ilość wystąpień mamy zliczoną w 
		// L[i] występuje więcej razy niż wcześniej znana najczęściej występująca 
		if (L[i] > maxv)
		{
			// to podmieniamy licznik 
			maxv = L[i]; 
			// aktualnie najczęściej występowała wartość i + minv
			index = i; 
		}
	}
	// po wykonaniu pętli w zmiennej index przechowujemy index pod którym w tablicy L[] znajduje się największa liczba wystąpień.
	// Przypomnijmy, że L[i] zliczało wystąpienia wartości (i + minv)
	/// ================================= 

	/* WYŚWIETLENIE REZULTATÓW */ 
	/// =================================
	cout << "Dominanta zbioru: \n"; 
	for (int i = 0; i < l_elementow; ++i)
		cout << T[i] << " "; 

	cout << "\nTo: " << index + minv << "\nWystapila " << L[index] << " razy.\n";
	/// ================================= 


	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */ 
	/// ================================= 
	delete[] T; delete[] L;
	/// ================================= 

	return 0; 
}
