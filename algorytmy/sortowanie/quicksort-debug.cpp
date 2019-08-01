
/*
	Quicksort!  
*/


#include <iostream>
#include <time.h>
using namespace std;

/* FUNKCJE I ZMIENNE DO DEBUGOWANIA */
/// ===============================
void print(const string& s)
{
	cout << s << "\n";
}

// zmienna globalna jest automatycznie zerowana
int ID;
/// ===============================


/* ALGORYTM SORTUJĄCY */
/// ============================== 
// w naszym podejściu jako pivot wybieramy element środkowy zbioru
// może to być dowolna inna wartość, mediana, element losowy itd. 
template<class C>
void quicksort(C T[], int ilp, int ipk)
{
	int id = ++ID;

	// w naszym podejściu jako pivot wybieramy element środkowy zbioru
	// może to być dowolna inna wartość, mediana, element losowy itd. 
	int i_pivot = (ilp + ipk) / 2; 

	cout << "wywolano funkcje quicksort() ID: " << id << ",\ndla danych: ilp = " << ilp << " ipk = " << ipk << " pivot = " << i_pivot << " T[pivot] = " << T[i_pivot] << "\n";
	cout << "rozwazany fragment tablicy: ";
	for (int i = ilp; i <= ipk; ++i)
		cout << T[i] << " ";
	cout << "\n";
	
	// zamieniamy miejscami pivot z ostatnim elementem sortowanej tablicy
	C buffer; 
	buffer = T[ipk]; 
	T[ipk] = T[i_pivot];
	T[i_pivot] = buffer;
	
	cout << "rozwazany fragment tablicy (po zamianie): ";
	for (int i = ilp; i <= ipk; ++i)
		cout << T[i] << " ";
	cout << "\n";

	// dzielimy nasz zbiór na 2 partycje 
	// elementy mniejsze do pivotu umieszczamy po lewej stronie środka zbioru
	// elementy większe od pivotu umieszczamy po prawej stronie środka zbioru
	// pozycja elementów równych pivotowi nie musi być zmieniana
	// i to bieżący iterator lecący przez zbiór. Warunek kończący 
	// j jest iteratorem pilnującym element który będziemy zamieniać. 
	// i < ipk bo T[ipk] to teraz pivot, więc nie ma sensu go porównywać z samym sobą. 
	// robimy to pętlą while, bo potrzebujemy mieć zapamiętane wartości iteratorów na później
	// do rekurencyjnego wywoływania się na partycjach
	register int i = ilp, j = ilp; 
	while (i < ipk)
	{
		// jeżeli przeglądająć tablicę znaleźliśmy element mniejszy od pivotu, to chcemy umieścić go
		// po lewej stronie środka zbioru,
		// pamiętajmy, że T[ipk] przechowuje w sobie wartość piwotu 
		if  (T[i] < T[ipk])
		{
			buffer = T[j]; 
			T[j] = T[i]; 
			T[i] = buffer;
			++j; 
		}
		++i;
	}
	// brak dalszych elementów do przeglądania, teraz pivot, wymieniamy z elementem na pozycji j-tej (bo pivot < T[j] -- gdyby było inaczej
	// to nasz algorytm by zmienił pozycję T[j] gdy był tam iterator i (chyba jasne xD))
	// btw. jest to kluczowe, aby zamienić te elementy, 
	buffer = T[j]; 
	T[j] = T[ipk];
	T[ipk] = buffer;

	cout << "rozwazany fragment tablicy po while'u: ";
	for (int k = ilp; k <= ipk; ++k)
		cout << T[k] << " ";
	cout << "\n";
	// po wykonaniu tej pętli powinniśmy mieć tablicę podzieiloną na dwie partycje, wszystkie elementy 
	// mniejsze od pivotu powinny znaleźć się na indeksach mniejszych od j. 

	// teraz wywołujemy się rekurencyjnie na lewej i na prawej partycji
	// jeżeli lewa partycja jest niepusta to wywołujemy się na niej
	if (ilp < j)
	{
		cout << "wywolanie na lewym przedziale z poziomu funkcji: " << id << "\n";
		quicksort(T, ilp, j - 1);		
	}

	// analogicznie dla prawej partycji 
	// jeżeli indeks elementu na prawo od ostatniego zamienionego elementu nie wychodzi poza granice 
	// rozważanego przedziału to się na nim wywołujemy 
	if (j + 1 < ipk)
	{
		cout << "wywolanie na prawym przedziale z poziomu funkcji: " << id << " \n";
		quicksort(T, j + 1, ipk);
	}
}
/// ============================== 




template<class C>
void wyswietl_tablice(C T[], int l_elementow, const string& s)
{
	int licznik = 0;
	cout << s << "\n";
	for (int i = 0; i < l_elementow; ++i, ++licznik)
	{
		if (licznik == 15)
		{
			cout << "\n"; 
			licznik = 0; 
		}

		cout << T[i] << " ";
	}
	cout << "\n";
}

int main()
{
	srand(time(NULL));

	int l_elementow;

	cin >> l_elementow;

	int * T = new int[l_elementow];

	for (int i = 0; i < l_elementow; ++i)
		T[i] = rand() % 1000;

	wyswietl_tablice(T, l_elementow, "T[] przed sortowaniem");

	// sortowanie
	print("wywolanie quicksort()");
	quicksort(T, 0, l_elementow - 1);
	print("koniec quicksort()");
	wyswietl_tablice(T, l_elementow, "T[] po sortowaniu");



	delete[] T;
	return 0; 
}
