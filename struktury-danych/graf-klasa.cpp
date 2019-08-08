/* 
	Klasa reprezentująca graf. Pamiętajmy o tym, że graf można równie dobrze (czy napewno?) reprezentować 
	poprzez tablicę wektorów, (list jednokierunkowych) czy macierz. Ta struktura jednak pozwala na ładne, 
	przejrzyste i wygodne reprezentowanie grafu wraz z danymi z nim skojarzonymi. 


	Kilka rzeczy zawartych w tym pliku nie jest potwierdzone z żadną literaturą, ani nigdzie wcześniej się 
	z nimi nie spotkałem, a jedynie sprawdzone eksperymentalnie przeze mnie. Zapisy takie są umieszczone w cudzysłowach. 
*/ 

#include <iostream>
#include <vector>
using namespace std;

/// GRAF BĘDZIEMY REPREZENTOWAĆ JAKO LISTĘ SĄSIEDZTWA
/// korzystamy z bibliotek STL, ale równie dobrze możemy zaimplementować własną listę sąsiedztwa (lub stos, czy jakąkolwiek
/// stosowaną strukturę danych) i mieć graf

/* STRUKTURA REPREZENTUJĄCA GRAF */
/// ======================================
// G == (V, E). 
// V - (vertices) - zewnętrzna klasa reprezentująca dodatkowe dane skojarzone z wierzchołkami. 
// E - (edges) - zewnętrzna klasa reprezentująca dodatkowe dane skojarzone z krawędziami. 
// poprzez 'dodatkowe dane' rozumiemy wagi, kolory, cokolwiek. Np. do reprezentacji samej krawędzi (rozumianej
// jako para wierzchołków (begin, end) nie potrzebujemy żadnych dodatkowych pól w klasie E)
// Korzystamy ze struct ze względów praktycznych, wszsytko co w środku ma być publiczne. 
template<class V, class E> struct Graph
{
	
	/* STRUKTURA REPREZENTUJĄCA POJEDYNCZĄ KRAWĘDŹ */
	/// ======================================
	// dziedziczenie publiczne z klasy E pozwala na dostęp do wszystkich danych skojarzonych z krawędzią
	struct Edge : public E
	{
		// nr wierzchołka końcowego krawędzi
		// początkowego nie potrzebujemy, bo będzie reprezentowany przez indeks wektra (no tak jak w zwykłej liście sąsiedztwa)
		int end;

		// wszystkie dodatkowe dane skojarzone z każdym z wierzchołków dziedziczymy z klasy E

		// Zaimplementowanie konstruktora pozwala na uproszeczenie zapisu pewnych algorytmów (wyjdzie w praniu) 
		// do każdej z krawędzi pobieramy jej wierzchołek końcowy oraz set danych z nią skojarzonych. "W taki sposób działa 
		// właśnie konstruktor E(E&). Nie trzeba go implementować w klasie E, wszystko wskazuje na to że jest to realizowane 
		// domyślnie. W każdym razie, nawet jeśli ten mechanizm technicznie działa inaczej, to efekt działania jest następujący:
		// wszystkie pola odziedziczone z klasy podstawowej E, są inicjowane takii wartościami jakie mają w obiekcie 'data' ".
		Edge(int end, E data) : end(end), E(data) {}
	};
	/// ======================================

	/* STRUKTURA REPREZENTUJĄCA POJEDYNCZY WIERZCHOŁEK */
	/// ======================================
	// dziedziczenie z klasy V pozwala na dostęp do wszystich pól przechowujących dane skojarzone z każdym z wierzchołków 
	// dziedziczenie z klasy vector<Edge>:
	/* 
		"Tutaj sprawa jest dosyć ciekawa, nigdzie indziej się z czymś takim wcześniej nie spotkałem.
		1. Każdy obiekt klasy 'Vertex' będzie miał w sobie wektor na typ Edge. 
			Tzn., rozważmy następujący kod: (oraz załóżmy, że w strukturze V mamy pole 'data')

			Vertex v; 
			v.data = 3;
			v.push_back(4); 

			Kod ten będzie poprawny, w polu 'data' przechowywana będzie wartość 3, natomiast w v[0] będziemy mieć wartość 4. 

		2. Będziemy mieć dostęp do iteratów na typ vector<Edge>, co będzie pozwalało na łatwe iterowanie przez graf
	*/ 
	struct Vertex : public V, public vector<Edge>
	{
		// nie potrzebujemy tutaj żadnych pól. 
	};
	/// ======================================

	/* WEKTOR WIERZCHOŁKÓW W GRAFIE */
	/// ======================================
	// pamiętajmy o tym, że każdy z wierzchołków (elementów tego wektora) ma w sobie wektor na krawędzie
	vector<Vertex> graph;
	/// ====================================== 

	/* KONSTRUKTOR GRAFU */
	/// ======================================
	// jeżeli nie jest podany rząd grafu (liczba jego wierzchołków), to wektor na wierzchołki ma wielkość 0
	// jeżeli jest podany rząd grafu, to ustawiamy rozmiar wektora na wierzchołki. 
	// Zdziwiło mnie trochę że można wywołać konstruktor już po wcześniejszym zapisaniu linijku z deklaracją obiektu. 
	// Chociaż pamiętajmy o tym, że zawsze najpierw wywoływany jest konstruktor. 
	Graph(int n_vertices = 0) : graph(n) {}
	/// ======================================

	/* METODA DODAJĄCA KRAWĘDŹ SKIEROWANĄ DO GRAFU */
	/// ======================================
	/* 
		D - directed
		b_vertex - wierzchołek początkowy krawędzi
		e_vertex - wierzchołek końcowy krawędzi
		data - obiekt klasy E z danymi które będziemy kojarzyć z daną krawędzią. 
				jeżeli nie jest przesłany żaden konkretny, to przesyłany jest automatycznie obiekt 
				zainicjowany przez domyslny konstruktor. (Nawet jeżeli nie ma go zaimplementowanego w klasie E, 
				to przecież pamiętajmy że konstruktor (jak i destruktor) domyślny tworzy za nas kompilator)
	*/
	void addEdgeD(int b_vertex, int e_vertex, E data = E())
	{
		/* graph(b_vertex) to obiekt klasy Vertex. Zatem do wektora na elementy klasy Edge, znajdującego się w każdym obiekcie 
		klasy Vertex, dodajemy indeks wierchołka końcowego krawędzi wraz z danymi skojarzonymi z tą że (jak to się pisze? D:) krawędzią. */
		// dziwi mnie, że jako argument do funkcji push_back(…) można przesłać KONSTRUKTOR. Coś kojarzę że konstruktor nie zwraca żadnej
		// wartości. Najwyraźniej jednak jest tworzony nowy obiekt i przesyłany jako parametr aktualny. 
		graph(b_vertex).push_back(Edge(e_vertex, data));
	}
	/// ======================================
};
/// ======================================
