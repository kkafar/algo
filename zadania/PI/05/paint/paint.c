/**
 * K. Kafara
 */

#include <stdio.h> 
#include <stdlib.h> 


struct Task
{
	int w, k, c;
};
typedef struct Task task;


int main(void)
{
	int n, z; 

	int finished_tasks = 0, started_tasks = 0;

	scanf("%d %d", &n, &z);

	int arr[n][n];

	// kolejka na zadania, oraz 2 indeksy do poruszania się po kolejce
	// b - początek kolejki
	// e - koniec kolejki
	// stc[b] jest poprawnym odwołaniem gdy b <= e
	int n2 = n * n;
	int b = 0, e = n2 - 1;
	task stc[n2];
	//printf("%d %d\n", b, e);
	// wczytujemy obrazek
	for (int i = 0; i < n; ++i)	
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d", (*(arr + i) + j));
		}
	}
	
	// wczytujemy zadania
	for (int i = 0; i < z; ++i)
	{
		scanf("%d %d %d", &stc[i].w, &stc[i].k, &stc[i].c);
	}
	// bo wczytaliśmy z zadań
	e = (e + z) % n2;
	started_tasks += z;
	//printf("%d %d\n", b, e);
	// zmienne do aktualnie przetwarzanego zadania
	int w, k, c;
	// Pobieramy zadanie z kolejki, rezlizujemy je, wrzucamy wszystkie sąsiednie pola do kolejki
	
	while (finished_tasks != started_tasks)
	{
		// pobieramy zadanie z kolejki 
/* 		printf("Kolejka: b: %d  e: %d\n", b, e);
		for (int i = 0; i < n2; ++i)
			printf("(%d, %d, %d) ", stc[i].w, stc[i].k, stc[i].c);
		printf("\n"); */

		//printf("Pobieram zadanie %d\n", b);
		w = stc[b].w;
		k = stc[b].k;
		c = stc[b].c;

		// kolorujemy pole
		arr[w][k] = c;
		++finished_tasks;
		
		// dodajemy do kolejki wszystke sąsiednie pola, o ile znajdują się w zakresie tablicy lub nie są już pokolorowane
		b = (b + 1) % n2;
		// pole nad rozważanym
		if (w >= 1 && arr[w - 1][k] == 0)
		{
			e = (e + 1) % n2;
			//printf("Dodaje zadanie %d  (%d, %d, %d)\n", e, w - 1, k, c);
			stc[e].w = w - 1;
			stc[e].k = k;
			stc[e].c = c;
			++started_tasks;
		}
		// pole na lewo od rozważanego
		if (k >= 1 && arr[w][k - 1] == 0)
		{
			e = (e + 1) % n2;
			stc[e].w = w;
			stc[e].k = k - 1;
			stc[e].c = c;
			++started_tasks;
		}
		// pole na prawo od rozważanego
		if (k + 1 < n && arr[w][k + 1] == 0)
		{
			e = (e + 1) % n2;
			stc[e].w = w;
			stc[e].k = k + 1;
			stc[e].c = c;
			++started_tasks;
		}
		// pole poniżej rozważanego
		if (w + 1 < n && arr[w + 1][k] == 0)
		{
			e = (e + 1) % n2;
			stc[e].w = w + 1;
			stc[e].k = k;
			stc[e].c = c;
			++started_tasks;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
			printf("%d ", arr[i][j]);

		printf("\n");
	}

	return 0;
}
