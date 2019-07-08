#include <iostream>
#include <list>
using namespace std;
 
void sortowanie_kubelkowe(int T[], list<int> L[], int rozmiar_tablicy)
{
	for (int i = 0; i < rozmiar_tablicy; ++i)
		L[T[i]].push_back(T[i]);
}
 
template<class C>
void wyswietl_tablice(C T[], int rozmiar_tablicy)
{
	for (int i = 0; i < rozmiar_tablicy; ++i)
		cout << T[i] << " ";
	cout << endl;
}
 
int main()
{
	list<int> * L;
	int liczba_przypadkow, rozmiar_tablicy, MAX, *T, index;
 
	cin >> liczba_przypadkow;
 
	for (int i = 0; i < liczba_przypadkow; ++i)
	{
		index = 0; 
		cin >> rozmiar_tablicy >> MAX;
 
		T = new int[rozmiar_tablicy];
		L = new list<int>[MAX];
 
		for (int i = 0; i < rozmiar_tablicy; ++i)
			cin >> T[i];
 
		sortowanie_kubelkowe(T, L, rozmiar_tablicy);
 
		index = 0;
		for (int i = 0; i < MAX; ++i)
		{
			while (!L[i].empty())
			{
				T[index] = L[i].back();
				L[i].pop_back();
				++index;
			}
		}
 
		wyswietl_tablice(T, rozmiar_tablicy);
 
		delete[] L;
		delete[] T;
	}
 
	return 0;
}
