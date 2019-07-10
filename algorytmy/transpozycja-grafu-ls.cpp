/*
	Transpozycja grafu reprezentowanego listą sąsiedztwa
	Transpozycja oznacza de facto obrócenie krawędzi skierowanych w przeciwną stronę. 
	Można to robić od razu na wejściu, podmieniając w_startowy i w_koncowy.

	Dla grafów reprezentowanych poprzez macierz sąsiedztwa i macierz incydencji
	zadanie to jest jeszcze prostsze. 
	
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void wyswietl_graf(vector<int> * graf, int l_wierzcholkow, const string& s);


/* FUNKCJA TRANSPONUJĄCA G W GT */
void transpozycja(vector<int> * G, vector<int> * GT, int l_wierzcholkow)
{
	// pętla iterująca po wszystkich listach sąsiedztwa początkowego grafu
	for (int i = 0; i < l_wierzcholkow; ++i)
	{
		// odwiedzamy wszystkich sąsiadów wierzchołka i
		for (auto j = G[i].begin(); j != G[i].end(); ++j)
		{
			// do grafu GT wpisujemy krawędzie przeciwnie skierowane
			GT[*j].push_back(i);
		}
	}
}

int main()
{
	/* WEJŚCIE, ZMIENNE, OBSŁUGA */
	///===============================
	int l_krawedzi, l_wierzcholkow, w_startowy, w_koncowy;

	cin >> l_wierzcholkow >> l_krawedzi;
	///===============================
	
	/* REZERWOWANIE PAMIĘCI NA GRAF */
	///===============================
	// graf wyjściowy
	vector<int> * G = new vector<int>[l_wierzcholkow];	
	// graf przetransponowany od razu na wejsciu
	vector<int> * GT = new vector<int>[l_wierzcholkow];
	// graf przetransponowany 
	vector<int> * GT2 = new vector<int>[l_wierzcholkow];
	///===============================

	/* WCZYTYWANIE GRAFU */
	///===============================
	for (int i = 0; i < l_krawedzi; ++i)
	{
		cin >> w_startowy >> w_koncowy;
		G[w_startowy].push_back(w_koncowy);
		// od razu zapisujemy sobie graf transponowany
		GT[w_koncowy].push_back(w_startowy);
	}
	///===============================

	/* TRANSPOZYCJA GRAFU G */
	///===============================
	transpozycja(G, GT2, l_wierzcholkow);
	///===============================


	/* WYŚWIETLANIE REZULTATÓW */
	///===============================
	wyswietl_graf(G, l_wierzcholkow, "G");
	wyswietl_graf(GT, l_wierzcholkow, "GT");
	wyswietl_graf(GT2, l_wierzcholkow, "GT2");
	///===============================


	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	///=============================== 
	delete[] G; delete[] GT; delete[] GT2;
	///===============================
	return 0;
}

void wyswietl_graf(vector<int> * graf, int l_wierzcholkow, const string& s)
{
	cout << "GRAF " << s << "\n";
	for (int i = 0; i < l_wierzcholkow; ++i)
	{
		cout << i << ": ";
		for (auto j = graf[i].begin(); j != graf[i].end(); ++j)
		{
			cout << *j << " ";
		}
		cout << "\n";
	}
}
