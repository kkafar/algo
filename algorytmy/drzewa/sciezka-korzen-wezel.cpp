/* 
	Wyznaczanie ścieżki z korzenia do każdego z węzłów drzewa.
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	DLA DRZEWA ZRÓWNOWAŻONEGO I UPORZĄDKOWANEGO 
	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	(wg następującej def:  binarne drzewo jest zrównoważone i uporządkowane, jeśli na wszystkich 
	poziomach za wyjątkiem ostatniego posiada maksymalną liczbę węzłów, a na poziomie ostatnim węzły 
	są ułożone kolejno od lewej strony. Innymi słowy, jeśli ostatni węzeł drzewa binarnego posiada 
	numer i-ty, to drzewo zawiera wszystkie węzły od numeru 1 do i.)
*/

// makro zupełnie dla zabawy, żeby poćwiczyć stosowanie
#define FOR(iterator, lower_bound, upper_bound) for (int iterator = lower_bound; iterator <= upper_bound; ++iterator)

#include <iostream>
#include <time.h>
#include <stack>
using namespace std;

/* PODEJSCIE 1 */
// Pamiętajmy od tym, że ta metoda to wyraźny przerost formy nad treścią, gdyż to zadanie można rozwiązać znacznie prościej 
// chodzi jednak o cele ćwiczeniowe.
/// =====================================
// coś ala BFS dla drzewa, wykorzystujący fakt, że jeżeli 2 * indeks_wezla > l_elementow_drzewa to węzel ten nie ma potomka
// a zatem jest liściem. (pamiętajmy o tym, że to drzewo zrównoważone i uporządkowane)

/*
Zaczynami rozptrywanie drzewa od korzenia. 
Jak w BFS: 
1. Dodajemy korzeń do kolejki. 
2. Wierzchołek z którego przyszliśmy do korzenia ustawiamy jako korzeń. 
3. Pętla while, (dopóki kolejka nie jest pusta)
 	3.1. Pobieramy pierwszy element z kolejki.
 	3.2. Jeżeli węzły o indeksach  2 * i  lub (2 * i + 1) należą do drzewa (nie wychodzą poza jego rozmiar)
 		to skoro jest to drzewo zrównoważone i uporządkowane to są to dzieci węzła i. 
 	3.3. Uzupełniamy tablicę poprzedników dla węzłów 2i i (2i + 1)
 	3.4. Dodajemy węzły 2i i 2i+1 do kolejki. 
 	3.5. Wróć do kroku 3.

* Kolejkę będziemy reprezentować poprzez zwykłą tablicę jednowymiarową rozmiaru równego 
 liczbie węzłów drzewa dla którego wywołujemy algorytm. 

* Pamiętajmy aby tablica poprzedników prev_node[] była zadeklarowna w postaci prev_node[ nodes + 1 ], aby istniał w niej element
 o indeksie 'nodes'.

* Jako że rozważaną strukturą jest drzewo, to nie ma potrzeby sprawdzania czy dany węzeł już był odwiedzony, bo w każdym węźle powinniśmy 
 znaleźć się tylko jeden raz.
*/

template<class C>
void bfs(C * D, int nodes, int * prev_node)
{
	// przygotowujemy kolejkę FIFO | (nodes + 1), bo węzły w drzewie numerujemy od 1, nie od 0. 
	int q[nodes + 1];

	// poprzednika korzenia ustawiamy jako korzeń
	prev_node[1] = 1; 

	// definiujemy sobie iteratory: 
	// i - przebiegający po drzwie (przechowuje aktualnie rozważany węzeł)
	// j - śledzący indeks pierwszego elementu w kolejce
	// k - śledzący miejsce w kolejce w które wstawiamy nowy element
	int i = 1, j = 1, k = 1;

	// dodajemy korzeń do kolejki i od razu zwiększamy iterator k (bo następny element będziemy już wstawiać)
	// na kolejny indeks
	q[k++] = 1; 

	// jeżeli w kolejce znajdują się jeszcze jakieś elementy 
	// można to chyba napisać na kilka równoważnych sposobów: 
	// 1. j <= nodes (bo to oznacza że jeszcze nie odwiedziliśmy wszystkich węzłów) (a mamy odwiedzić wszystkie)
	// 2. j <= k     (k nigdy nie powinno być większe niż nodes, a j zawsze <= k, właściwie z definicji)
	// 3. jeszcze pewnie da się coś wymyślić …
	while (j <= nodes)
	{
		// pobieramy pierwszy węzeł w kolejce | od razu inkrementujemy także iterator j (oczywiste)
		i = q[j++];

		// jeżeli lewe dziecko należy do drzewa
		if (2 * i <= nodes)
		{
			// ustawiamy węzeł z którego przyszliśmy 
			prev_node[2 * i] = i;
			// dodajemy lewe dziecko do kolejki, a następnie zwiększamy iterator k
			q[k++] = 2 * i; 
		}

		if (2 * i + 1 <= nodes)
		{
			// ustawiamy węzeł z którego przyszlismy 
			prev_node[2 * i + 1] = i;
			// dodajemy prawe dziecko do kolejki, a następnie zwiększmy iterator k
			q[k++] = 2 * i + 1;
		}

	}
	// po wykonianiu pętli tablica prev_nodes powinna być kompletna, a zatem znamy ścieżki od korzenia do każdego z węzłów
	
}

// wyświetlanie ścieżek
void write(int nodes, int * prev_node) 
{

	cout << "(NR WEZLA): (SCIEZKA)\n";
	FOR(i, 1, nodes)
	{
		stack<int> s;
		cout << i << ": ";

		s.push(i);
		while(i > 1)
		{
			i = prev_node[i]; 
			s.push(i);
		}

		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << "\n";
		
	}
}
/// =====================================

template<class C> 
void print_tree(C * D, int nodes)
{
	int lvl = 1, counter = 1; 
	FOR(i, 1, nodes)
	{
		cout << D[i] << " "; 
		if (counter == lvl)
		{
			counter = 0; 
			lvl <<= 1;
			cout << "\n";
		}
		++counter; 
	}
	cout << "\n";
}

int main()
{
	// zmienna przechowująca liczbę węzłow w drzewie 
	int l_wezlow; 

	// pobieramy liczbę węzłów drzewa
	cin >> l_wezlow; 

	// tablica reprezentująca drzewo, pamiętajmy aby miała indeksy nie od 0 do l_wezlow-1, tylko od 1 do l_wezlow (0 pomijamy)
	int * D = new int[l_wezlow + 1];

	// tablica wierzchołków poprzedzających tzn. w prev_node[i] przchowujemy indeks ojca węzła o indeksie i. 
	// tak samo pamiętamy, aby przesunąć indeksowanie o 1 w prawo
	int * prev_node = new int[l_wezlow + 1];

	// pobieramy wartości kolejnych węzłów drzewa (po kolei od węzła o indeksie 1, do węzła o indeksie l_wezlow)
	FOR(i, 1, l_wezlow)
		cin >> D[i];

	// wyświetlamy drzewo 
	print_tree(D, l_wezlow);
	
	// wywołujemy algorytm bfs
	bfs(D, l_wezlow, prev_node);

	// zawartość tablicy poprzedników
	FOR(i, 1, l_wezlow)
	{
		cout << prev_node[i] << " ";
	}
	cout << "\n";

	// prezentujemy rezultaty działania algorytmu
	write(l_wezlow, prev_node);

	delete[] prev_node;
	delete[] D; 
	return 0; 
}A
