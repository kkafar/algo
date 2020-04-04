/**
 * K. Kafara
 */

#include <stdio.h> 
#include <stdlib.h> 

struct Task
{
	char *number;
	int sec;
};
int sti(char * n, int i, char ** n_beg)
{
	char * ch = n + i;
	int numb = 0;
	int len = 0;
	// printf("sti 1\n");
	// znajdujemy długość liczby w jej zapisie dziesiętnym 
	while (*ch != ' ' && *ch != '\n')
	{
		// printf("%c ", *ch);
		++len;
		++ch;
	}

	// printf("sti 2\n");
	*n_beg = n + i + len + 1;

	// printf("%d\n", len);
	ch = n + i;

	while (ch < n + i + len)
	{
		numb = numb * 10 + ((int)((*ch) - '0'));
		++ch;
	}
	// printf("sti 3\n");
	return numb;
}

char * get_number(char * beg, char * line)
{
	// printf("gn1\n");
	char * end = beg;
	
	while (end != NULL && *end != '\n')
		++end;
	
	// printf("gn2\n");
	--end;

	char * number = (char *) malloc((end - beg + 1) * sizeof(char));
	register int i = 0;
	for (char * ptr = beg; ptr <= end; ++ptr)
		number[i++] = *ptr;
	
	// printf("gn3\n");
	return number;
}


int main(void)
{
	int n, sec;

	scanf("%d", &n);

	/**
	 * Rozwiązanie i wyjaśnienie znalezione na stackoverflow
	 * wpisując znak z klawiatury, klikając enter wstawiamy do bufora zamierzony znak
	 * oraz dodatkowo znak końca linii, którego scanf nie zbiera ==> zostaje on w buforze
	 * gdy uruchamiamy fgets() to funkcja natychmiast przerywa swoje wykonanie napotykając znak końca linii. 
	 * Dlatego zbieramy z bufora wszystko do pierwszego znaku nowej linii. 
	 */
	while ((getchar()) != '\n');

	// kolejka i zmienne do poruszania się po niej
	struct Task tsk[n];
	char line[30], * number_beg;
	int b = 0, e = n - 1;

	for (int i = 0; i < n; ++i)
	{
		fgets(line, 30, stdin);
		// printf("0\n");
		// printf("%c\n", line[0]);
		// dodajemy zadanie do kolejki
		// printf("LINIA: %s", line);
		if (line[0] == 'a')
		{
			e = (e + 1) % n;
			tsk[e].sec = sti(line, 2, &number_beg);
			// printf("%d\n", tsk[e].sec);
			// printf("1\n");
			tsk[e].number = get_number(number_beg, line);
			// printf("%s\n", tsk[e].number);
			// printf("2\n");
		}

		// ściąganie zadania z kolejki i wypisywanie rezultatu
		else
		{
			sec = sti(line, 2, &number_beg);
			// printf("%c\n", line[2]);
			// printf("sec: %d\n", sec);
			printf("%s %d\n", tsk[b].number, sec - tsk[b].sec);
			// ściągamy z kolejki
			b = (b + 1) % n;
		}
	}
	return 0;
}
