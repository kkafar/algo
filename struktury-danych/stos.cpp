/* 
	Własna implementacja stosu. 

	Cel:
	Struktura danych stos: 
	1. dająca dostęp do ostatneigo umieszczonego na nim elementu metodą top()
	2. pozwalającą na usunięcie ze stosu szczytowego elementu metodą pop()
	3. metoda push() pozwalająca na dodanie do listy elementu o zadanej wartości 
	4. metoda size() zwracająca aktualny rozmiar stosu
*/ 	

/*
	Ta implementacja ma pewne problemy: 
	1. Za każdym razem gdy dodajemy element do stosu tworzymy nowy obiekt z nowym wskaźnikiem "under" (który jest potrzebny
	oraz z nowym wskaźnikiem 't' który już potrzebny nie jest. Pasowałoby żeby wskaźnik 't' był zmienną statyczną, 
	ale nie dokońca ogarniam jak to poprzerabiać żeby działało. 
*/

#include <iostream>
#include <time.h>

using namespace std;

template<class C>
class Stack
{
private:
	// wskaźnik na element który w stosie znajduje się pod nami
	Stack<C> * under;
	// wskaźnik na element na szczycie stosu  
	Stack<C> * t;

	// zmienna przechowująca aktualny rozmiar stosu
	unsigned int size;

	// zmienna przechowująca wartość danego elementu 
	C value;

public:
	// konstruktor
	Stack()
	{
		under = NULL;
		t = NULL;
		size = 0; 
	}
/*
	// dekonstruktor
	~Stack()
	{
		// zmienna pomocnicza do usuwania kolejnych elementow
		Stack<C> * p;
		// wywołamy się dla każdego elementu należącego do stosu
		for (int i = 0; i < size; ++i)
		{
			// ustawiamy się na szczytowym elemencie
			p = top; 
			// wskaźnik top, wskazuje na element klasy Stack<C> 
		}
	}
*/
	// metoda dodająca kolejny element do stosu 
	void push(C val)
	{
		// ustawiamy 'wskaźnik na element pod nami' na nowy element
		Stack<C> * under = new Stack<C>;
		
		// ustawiamy wartość nowego elementu
		under->value = val;

		// ustawiamy adres elementu pod 'nowym elementem' na obecny sczyt
		under->under = t;

		// ustawiamy wskaźnik na szczyt na nowy element
		t = under;

		// zwiększamy rozmiar stosu o jeden 
		++size;
	}

	// chcemy pozbyć się szczytowego elementu
	// 1. wskaźnik na element szczytowy ustawimy na element pod nami 
	// 2. wskaźnik na element pod elementem szczytowym ustawiamy na NULL, 
	void pop()
	{
		Stack<C> * del = t; 
		t = t->under; 
		del->under = NULL;
		--size; 
	}

	int getSize()
	{
		return size;
	}

	C top()
	{
		return t->value;		
	}
};


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
