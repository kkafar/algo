/**
 * K. Kafara
 */

#include <stdio.h> 
#include <stdlib.h> 

/**
 * \brief Konwersja string'a długośći len na liczbę dziesiętną
 */
int sti(char * n, int len)
{
	char * ch = n;
	int numb = 0;
	while (ch < n + len)
	{
		numb = numb * 10 + ((int)((*ch) - '0'));
		++ch;
	}

	return numb;
}

void solution(char * line, int n, int k)
{
	// bufer do którego będziemy wczytywać dane do przetworzenia, będzie działał na zasadzie stosu.
	// w buforze znajdują sie tylko znaki od ostatniej spacji
	// k + 1, bo jedna komórka zapasu nie zawadzi, a jest szansa że uniknę  debugowania :D
	// wskaźnik jest zawsze na ostatnim dodanym elemencie (odwołanie do buff[buff_idx] jest poprawne o ile buff_idx != -1)
	char buff[k + 1];
	int buff_idx = -1;

	// stos na już przetworzone liczby
	// n + 1 z takich samych przyczyn
	int stc[n + 1], stc_idx = -1;
	char * c_ptr = line;
	int n_count = 0, oper_count = 0;

	// 'n' to liczba, operator jest to jeden z symboli *, /, +, -.
	// Inicjalizujemy inną wartością, bo na starcie jeszcze nic nie mamy
	char last_ch = '9';

	while (n_count < n || oper_count < k)
	{
		if ((*c_ptr) >= '0' && (*c_ptr) <= '9')
		{
			last_ch = 'n';
			buff[++buff_idx] = *c_ptr;
			++n_count;
		}

		else if (*c_ptr == ' ')
		{
			if (last_ch == 'n')
			{
				stc[++stc_idx] = sti(buff, buff_idx + 1);
				buff_idx = -1;
			}
		}
		
		// else oznacza że obsługujemy operator
		else
		{
			last_ch = *c_ptr;
			++oper_count;

			switch(*c_ptr)
			{
				case '+':
					stc[stc_idx - 1] = stc[stc_idx - 1] + stc[stc_idx];
					break;
				case '-':
					stc[stc_idx - 1] = stc[stc_idx - 1] - stc[stc_idx];
					break;
				case '*':
					stc[stc_idx - 1] = stc[stc_idx - 1] * stc[stc_idx];
					break;
				case '/':
					stc[stc_idx - 1] = stc[stc_idx - 1] / stc[stc_idx];
					break;
				default:
					printf("DEFAULT w switchu\n");
			}
			--stc_idx;
		}
		
		++c_ptr;
	}

	printf("%d\n", stc[0]);
}


int main(void)
{
 	int n, k;
	
	scanf("%d %d", &n, &k);

	if (n == 1)
	{
		scanf("%d", &n);
		printf("%d\n", n);
	}
	else
	{
		char line[2 * (n * k + n - 1)];

		// z niewyjaśnionych przyczyn wykonuje się i tak tylko drugi fgets. Taki sam problem miałem 
		// kiedyś z getline()
		fgets(line, 5, stdin);
		fgets(line, 2 * (n * k + n - 1), stdin);

		// jeżeli nie ma co liczyć to wypisujemy

		solution(line, n, n - 1);
	}
	return 0;
}
