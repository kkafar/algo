/*
	https://main2.edu.pl/main2/courses/show/7/20/ + WYTŁUMACZENIE
	Treść zadania 
	Na n stosach ustawionych w rzędzie leży pewna liczba monet: na pierwszym stosie a1, 
	na drugim  a1, ..., na n-tym an. Wolno nam zabrać niektóre z tych stosów,
	ale nie wolno ruszyć dwóch sąsiednich. Jaka jest największa liczba monet, które można uzyskać?
*/ 

/* 
	Jest to problem bardzo podobny do zadania 'mosiężny most' z satorii. Zatem od razu nasuwa się 
	rozwiązanie poprzez programowanie dynamiczne. 
	Jest n stosów. Znamy A_i (wartość i-tego stosu, 1 ≤ i ≤ n). Rozważmy początkowe j stosów.
	Niech Z(j) oznacza maksymalną liczbę monet jaką można zabrać rozważając tylko j
	początkowych stosów. Zauważmy prosty fakt. Podchodząc do k-tego stosu mamy oczywiście 2 możliwości. 
	1. Bierzemy go, co oznacza że najwięcej ile możemy zebrać to (A_k + Z(k - 2)), bo stosu k-1 zabrać nie możemy, a wiemy
		że w Z(k - 2) znajduje się optymalna ilość do stosu k-2. 
	2. Nie bierzemy go, co oznacza że najwięcej ile możemy zebrać znajduje się w ostatnim wziętym przez nas stosie - k-1.

	Bierzemy maksa z tych dwóch podejść. 

	Nadmieńmy jeszcze że Z(0) = 0; Z(1) = A_1
*/ 

#include <iostream>
#include <math.h>
#include <time.h>
#include <iomanip>
using namespace std;

int main()
{
	srand(time(NULL));

	// liczba stosów
	int l_stosow;

	cin >> l_stosow; 

	int * A = new int[l_stosow + 1], * Z = new int[l_stosow + 1];

	for (int i = 1; i <= l_stosow; ++i)
		A[i] = rand() % 50 + 1;

	Z[0] = 0; 
	Z[1] = A[1];

	// sprawdzamy najpierw czy jest co liczyć
	if (l_stosow >= 2)
	{
		for (int i = 2; i <= l_stosow; ++i)
		{
			Z[i] = max( Z[i - 1], (A[i] + Z[i - 2]) );
		}
	}

	// w Z[l_stosow] powinniśmy mieć właściwą odpowiedź na pytanie postawione w zadaniu
	cout << "Ilosc monet w kolejnych stosach: \n";
	for (int i = 1; i <= l_stosow; ++i)
		cout << setw(4) << A[i];

	cout << "\n";

	for (int i = 1; i <= l_stosow; ++i)
		cout << setw(4) << i;

	cout << "\n";

	cout << "Najwiecej ile mozna zebrac to: " << Z[l_stosow] << "\n";

	

	delete [] A; delete[] Z;
	return 0;
}
