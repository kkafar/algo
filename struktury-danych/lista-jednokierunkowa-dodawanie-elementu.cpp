#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

/* KLASA REZPREZENTUJĄCA LISTĘ */
/// ===============================
template<class T>
class List
{
public:
	// zmienna przechowująca wartość danego elemtu listy
	T value;

	// wskaźnik na kolejny element listy
	// przypisujemy null, bo każdy nowo powstały element listy nie ma jeszcze 
	// swojego następnika
	List<T> * next = NULL;
};
/// ===============================

int main()
{

	srand(time(NULL));

	/* REZERWACJA PAMIĘCI */
	/// ===============================
	// tworzymy pustą listę 
	List<int> * list = NULL;

	// zmienna pomocnicza do dodawania nowych elementów na początek listy
	List<int> * newEl = NULL; 
	/// =============================== 

	/* UZUPEŁNIANIE LISTY */
	/// ===============================
	for (int i = 0; i < 15; ++i)
	{
		// rezerwujemy miejsce w pamięci dla nowego elemtnu listy
		// adres tego miejsca przechowuje teraz wskaźnik newEl
		newEl = new List<int>;

		// przypisujemy mu jakąś wartość 
		newEl->value = rand() % 50;

		// jako że wstawiamy na początek listy, to w elemencie newEl zapisujemy adres obecnego początku listy
		newEl->next = list;

		// nowo utworzony element staje się początkiem listy
		list = newEl;

		// no i tak w kółko
	}
	/// =============================== 

	/* WYŚWIETLANIE LISTY */
	/// ===============================
	// list powinien wskazywać na pierwszy element listy (dodany na samym końcu)
	// warunek kończący to "iter", bo ostatni element listy powinien wskazywać na NULL
	for (List<int> * iter = list; iter; iter = iter->next)
	{
		// wyświetlamy dany element listy
		cout << iter->value << " ";
	}
	cout << "\n";
	/// ===============================

	/* ZWALNIANIE ZAREZERWOWANEJ PAMIĘCI */
	/// ===============================
	// zmienna pomocnicza do usuwania elementów listy
	List<int> * p;
	// pętla iterująca przez kolejne elementy listy
	for (List<int> * iter = list; iter;)
	{
		// przypisujemy do zmiennej pomocniczej adres obecnie rozważanego elementu listy
		p = iter;
		// przestawiamy iterator na kolejny element LISTY
		iter = iter->next;
		// usuwamy element na który wskazuje wskaźnik p
		delete p;
	}

	// po wykonianiu pętli, p powinien wskazywać na NULL
	
	delete newEl; delete list;
	
	/// ===============================

	return 0;
}
