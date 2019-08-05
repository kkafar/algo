/* 
	Tworzenie kopca. 
	Kopiec to takie drzewo, w którym rodzic jest zawsze większy bądź równy swoim dzieciom (warunek kopca)

	Kopiec jest także drzewem zrównoważonym i uporządkowanym! (przynajmniej tutaj!) 

	Dodajemy do tego operacje rozbioru kopca, otrzymując de facto, sortowanie przez kopcowanie (heap sort)

*/ 

#include <iostream>
#include <time.h> 	// do generowania liczb losowych
using namespace std;

/* SORTOWANIE PRZEZ KOPCOWANIE */ 
// My przeprowzdzimy je w miejscu, ale równie dobrze można to robić z dodatkową tablicą. 
/* 
	Plan jest taki: 
	Na starcie, przed wywołaniem algorytmu nasze drzewo już zostało przerobione na kopiec, zatem operujemy na kopcu.
	Korzystamy z faktu, że zależnie od implementacji kopca, korzeniem jest zawsze najmniejsza lub największa wartość w zbiorze.
	Dla nas jest to wartość największa. 

	1. Zamieniamy miejscami korzeń z ostatnim liściem. 
	2. Zmniejszamy rozmiar kopca o 1, wykluczając tym samym ostatni element tablicy z analizy. 
	3. Korzeniem jest teraz wartość wcześniejszego ostatniego liścia ==> raczej na pewno, nie jest spełniony  warunek kopca. 
		Zatem trzeba teraz zadbać o to aby nasze drzewo było kopcem. 
	4. Wybieramy większe z dzieci i zamieniamy się z nim miejscami. (Wybór mniejszczego z oczywistych powodów nie ma sensu). 
	5. Powtarzamy 4. tak długo, aż dojedziemy węzłów spełniających warunek kopca. 
	6. Wracamy do 1. 	

*	Po wykonaniu algorytmu, w tablicy wcześniej przechowującej drzewo powinniśmy mieć posortwowany zbiór, pozostaje jedynie go wyświetlić. 
*/ 
/// ===============================
template<class C> void heapSort(C * D, int size)
{
	// zmienna do zamieniania miejscami korzenia z ostatnim liściem 
	// oraz root - indeks ojca 
	// lChild - indek lewego dziecka 
	int root, lChild, buffer;
	C buffer2; 
	// dopóki jakiś element znajduje się w kopcu 
	while (size)
	{
		// zamieniamy miejscem korzeń z ostatnim liściem
		// pamiętamy o tym, że drzewo indeksujemy od 1 do size
		buffer = D[1]; 
		D[1] = D[size];
		// od razu zmiejszamy rozmiar kopca o 1
		D[size--] = buffer;
	
		// do zmiennej pomocniczej przypisujemy indeks korzenia
		root = 1;
		// dopóki przeglądany węzeł ma dzieci, to mamy się z kim zamieniać miejscami
		while (2 * root <= size)
		{
			lChild = 2 * root;
			// jeżeli prawe dziecko jest większe od lewgo i należy do drzewa
			if (((lChild + 1) <= size) && (D[lChild + 1] > D[lChild])) 
				buffer = lChild + 1;

			// w innym wypadku to lewe dziecko jest większe, więc jego indeks zapisujemy 
			else 
				buffer = lChild;

			// teraz jeżeli większe z dzieci jest większe od ojca, to zamieniamy dziecko z ojcem miejscami
			if  (D[buffer] > D[root])
			{
				buffer2 = D[root];
				D[root] = D[buffer];
				D[buffer] = buffer2;
				root = buffer;
			}

			else 
				break;
		}

	}
	// w tablicy D powinien znajdować się teraz posortowany zbiór. 	
}

/// ===============================

/* PROCEDURA WYŚWIETLAJĄCA DRZEWO */ 
// =====================================
template<class C> void printTree(C * D, int nodes)
{
	int lvl = 1, counter = 1; 
	for (int i = 1; i <= nodes; ++i)
	{
		cout <<  " " << D[i];
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
// =====================================

template<class C> void printArray(C * T, int size)
{
	for (int i = 1; i <= size; ++i)
		cout << " " << T[i];
	cout << "\n";
}

int main()
{
	// zmienna przechowująca liczbę węzłów w drzewie
	// w - zmienna pomocnicza do rezlizowanai warunku kopca
	// buffer - zmienna pomocnicza służąca do podmiany wartości w tablicy
	int lWezlow, w, buffer;

	// pobieramy liczbe węzłów
	cin >> lWezlow;

	// tworzymy tablicę którą będziemy reprezentować drzewo (indeksy 1...lWezlow)
	double * D = new double[lWezlow + 1];
	double * D2 = new double[lWezlow + 1];


	// pobieramy kolejne węzły drzewa, od razu dbając o to, aby spełniony był warunek kopca. 
	// Każdy element w momencie dodania jest "ostatnim liściem" ==> sprawdzamy czy kolejni rodzice są od nas więksi, 
	// jeżeli tak, to zamieniamyu miejscami w tablicy odpowiednie dwa elementy. Jeśli nie, to znaczy że mamy kopiec
	// jak się patrzy :) 
	for (int i = 1; i <= lWezlow; ++i)
	{
		// generujemy dane kolejnych węzłów
		D[i] = rand() % 1000;
		// od razu tworzymy kopie drzewa do wyswietlenia
		D2[i] = D[i];

		/* TWORZENIE KOPCA */ 
		/// ===============================
		// realizujemy warunek kopca: 
		// zmienna pomocnicza w, którą będziemy podróżować przez kolejne pokolenia rodziców wierzchołka i
		w = i; 
		// będziemy przyrównywać się do w/2, więc w ostatniej iteracji pętli możemy być najwyżej dla w == 2
		while (w > 1)
		{
			// jeżeli rodzic jest mniejszy od swojego dziecka
			if (D[w/2] < D[w])
			{
				// to podmieniamy ich wartościami. Rodzic staje się dzieckiem, a dziecko rodzicem
				buffer = D[w]; 
				D[w] = D[w/2]; 
				D[w/2] = buffer;
				w /= 2; 
			}
			// jeżeli if się nie wykonał, to znaczy, że dziecko jest na właściwym miejscu (spełniony jest warunek kopca)
			// zatem możemy bezpiecznie przerwać działanie pętli 
			else 
				break;
		}
		/// ===============================
	}
	// po wykonaniu tej pętli nasze drzewo powinno być kopcem. 

	// wyświetlamy kopiec, i drzewo którego nie modyfikowalismy
	cout << "Drzewo: \n";
	printTree(D2, lWezlow);
	cout << "\nKopiec: \n";
	printTree(D, lWezlow);

	cout << "Zbior D przed sortowaniem: \n";
	printArray(D2, lWezlow);

	// sortowanie 
	heapSort(D, lWezlow);

	cout << "Zbior D po sortowaniu: \n";
	printArray(D, lWezlow);


	// zwalniamy zarezerwowaną pamięć 
	delete[] D; 
	delete[] D2; 
	return 0;
}
