/*
	WERSJA 2
	w tym podejściu dodając nowy element do stosu nie będziemy tworzyć nowego obietku klasy stos, a jedynie 
	będziemy tworzyć nowy węzeł! 

	link do wersji 1: https://github.com/kkafar/my-projects/blob/master/struktury-danych/stos.cpp

	Własna implementacja stosu.
	Cel:
	Struktura danych stos:
	1. dająca dostęp do ostatneigo umieszczonego na nim elementu metodą top()
	2. pozwalającą na usunięcie ze stosu szczytowego elementu metodą pop()
	3. metoda push() pozwalająca na dodanie do listy elementu o zadanej wartości
	4. metoda size() zwracająca aktualny rozmiar stosu
*/

#include <iostream>
#include <time.h>

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
			delete elementBeneath;
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
		delete first; 
		delete newEl;
	}
	/// ======================================


	

};
/// ======================================


int main()
{
	srand(time(NULL));
	int random, lElementow;

	cin >> lElementow;

	Stack<int> S;


	for (int i = 0; i < lElementow; ++i)
	{
		random = rand() % 1000;
		cout << "wylosowano: " << random << "\n";
		S.push(random);
	}

	cout << "Rozmiar stosu: " << S.getSize() << "\n";
	cout << "Element na samej gorze: " << S.top() << "\n";

	cout << "Zawartosc stosu: \n";
	while (S.getSize())
	{
		cout << S.top() << "\n";
		S.pop();
	}

	cout << "Rozmiar stosu: " << S.getSize() << "\n";

	return 0;
}
