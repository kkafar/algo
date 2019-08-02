/*
	Wyszukiwanie ścieżki w drzewie binarnym  od zadanego węzła do korzenia.
*/

#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

/* KLASA REPREZENTUJĄCA STOS */
/// ======================================
template<class C>
class Stack
{
private:
	// klasa reprezentująca pojedynczy element stosu
	class Element
	{
	public:
		// zmienna przechowująca wartość danego elementu 
		C value;
		// wskaźnik na element który znajduje się w stosie 'pod nami'
		Element * elementBeneath;

		Element()
		{
			elementBeneath = NULL;
		}

		~Element()
		{
			elementBeneath = NULL;
			// nie może być:
			// delete elementBeneath - bo wtedy usuwamy także element który jest pod nami, a nie tylko szczytowy
		}

	};

	// wskaźnik na pierwszy element stosu
	Element * first;
	// zmienna pomocnicza do tworzenia nowych elementów
	Element * newEl;

	// zmienna przechowująca aktualny rozmiar stosu
	unsigned int size;

public:

	/* METODY */
	/// ======================================
	// metoda dodająca nowy element do stosu.
	void push(C val)
	{
		// rezerwujemy miejsce w pamięci dla nowego elementu który zamierzamy dodać do stosu
		// w zmiennej newEl mamy jego adres. 
		newEl = new Element;

		// przypisujemy nowemu elementowi jakąś zadaną wartość
		newEl->value = val;

		// jako że nasz nowy element wędruje na przód stosu, to stary pierwszy element będzie bezpośrednio pod nowym elementem
		// ==> do pola newEl->elementBeneath przypisujemy adres starego sczytu
		newEl->elementBeneath = first;

		// wskaźnik wskazujący sczyt stosu ustawiamy na nowy szczyt
		first = newEl;

		// zwiększamy rozmiar stosu o 1
		++size;

	}

	// metoda usuwająca pierwszy element ze stosu 
	// jeżeli usuwanie zakończy się sukcesem (czyli np. jest co usuwać) to zwraca wartość true
	bool pop()
	{
		// jeżeli jest co usuwać (rozmiar stosu nie jest zerowy)
		if (size)
		{
			// skoro chcemy usunąć element, to usuwamy to na co wskazuje wskaźnik first, 
			// a wskaźnik first przestawiamy na element który wcześniej był 2 w kolejności od góry 
			// najpierw tworzymy zmienną pomocniczą do usuwania
			Element * el = first;
			// przestawiamy wskaźnik na 2 element 
			first = first->elementBeneath;
			// usuwamy stary pierwszy element
			delete el;

			// zmniejszamy rozmiar stosu 
			--size;

			// zwracamy true
			return true;
		}

		else
			return false;

	}

	// metoda zwracająca obecny rozmiar stosu
	unsigned int getSize()
	{
		return size;
	}

	// zwraca wartość pierwszego elementu 
	C top()
	{
		return first->value;
	}


	// konstruktor
	Stack()
	{
		size = 0;
		first = NULL;
		newEl = NULL;
	}

	// dekonstruktor
	~Stack()
	{
		//cout << "wywolano ~Stack()\n";
		delete first;
		delete newEl;
	}
	/// ======================================
};
/// ======================================


template<class C>
void wyswietl_drzewo(C * T, int rozmiar)
{
	int poziom = 1, licznik = 1;
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
	Stack<int> stack;
	// to wyświetla mi ścieżkę od tyłu 
	while (w >= 1)
	{
		stack.push(w);
		w /= 2;
	}

	while (stack.getSize())
	{
		cout << stack.top() << " "; 
		stack.pop();
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
