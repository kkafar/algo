/* 
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

template<class C>
class Stack
{
private:
	// wskaźnik na element który w stosie znajduje się pod nami
	Stack<C> * under;
	// wskaźnik na element na szczycie stosu  
	Stack<C> * t;

	int size;

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

	for (Stack<int> * i = (S.t); i; i = i->under)
		cout << i->value << "\n";
	cout << "\n";

	cout << "Usuwam dwa elementy od gory!\n";
	S.pop();
	S.pop();
	cout << "Rozmiar stosu: " << S.getSize() << "\n";
	cout << "Elemenet na samej gorze: " << S.top() << "\n";


	return 0; 
}
