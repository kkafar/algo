/*
	Implementacja i testowanie własnej listy jednokierunkowej.
	W ramach ćwiczenia zaprojektowana przeze mnie. 

	Każdy element listy, będzie zawierał swoją wartość i adres natępnego elementu w liście. 

	Celem jest dodanie losowo wygenerowanych liczb, wyświetlenie lisy, oraz następnie usunięcie
	jej elementów. 
*/
#include <iostream>
#include <time.h>
using namespace std;

template<class T>
class List
{
public:
	// wartośc danego elementu w liście
	T value = 0;

	// wskaźnik do następnego elementu w liście
	// inicjujemy NULL'em, żeby zawsze ostatni element listy
	// wskazywał na NULL
	List<T> * next = NULL;
};

int main()
{
	srand(time(NULL));

	/* REZERWACJA PAMIĘCI */ 
	// dla pierwszego elementu i wskaźnika na kolejne, które będziemy mogli dodawać
	/// ==============================
	// pierwszy element listy, którego adres jest nam stale potrzebny do wyświetlania listy
	List<int> * pierwszy = new List<int>; 
	// wskaźnik na nowy element, który będziemy mogli w każdej chwili dodać do listy
	List<int> * nowy;
	/// ==============================

	// pierwszemu elementowi nadaję jakąś wartość
	// na razie wskazuje na NULL
	pierwszy->value = 1;

	// w pierwszy przechowujemy adres następnego elementu
	pierwszy->next = nowy;

	/* DODAWANIE KOLEJNYCH ELEMENTÓW DO LISTY*/
	/// ==============================
	// a teraz już idzie automatycznie
	for (int i = 0; i < 10; ++i)
	{
		// nowy->next do tej pory wskazywał NULL
		// pamiętajmy że operator new zwraca adres miejsca w pamięci
		// w którym zostało zarezerwowane miejsce dla zmiennej
		// wobec tego, po wykonianiu tej linii, nowy->next wskazuje na miejsce w pamięci
		// w którym znajduje się kolejny obiekt klasy List<int>
		nowy->next = new List<int>;
		// przesuwamy wskaźnik nowy na adres tego kolejnego, nowego elementu
		nowy = nowy->next;
		// przypisujemy mu jakąś wartość
		nowy->value = rand() % 10;
		// i tak w koło
	}
	/// ==============================

	/* WYŚWIETLANIE ZAWARTOŚCI LISTY */
	/// ==============================
	// ustawiamy iterator na adres pierwszego elementu, po każdym kroku przesuwamy wskaźnik na kolejny element
	// warunek kończący to: ; i; bo ostatni element wskazuje na NULL
	for (List<int> * i = pierwszy; i; i = i->next)
		cout << i->value << " ";
	cout << "\n";
	/// ==============================


	return 0;
}
