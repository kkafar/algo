/**
 * K. Kafara
 */

#include <stdio.h> 
#include <stdlib.h> 



int main(void)
{
	/**
	 * Zaczynamy od małego uporządkowania terminologii i wyrzucenia z pierwszego planu 
	 * bardzo nieprecyzyjnych (i w gruncie rzeczy niepoprawnych) terminów "wskaźnik na wskaźnik"
	 * 
	 * W C/CPP każda zmienna zadeklarowana/zdefiniowana przez programistę musi mieć określony Typ - jest to ważne, 
	 * ponieważ Typ decyduje o tym w jaki sposób działają niektóre elementy języka (np. operatory arytmetyczne)
	 * oraz m.in. w jaki sposób dane te są interpretowane na dysku. 
	 * 
	 * Jednym z typów danych są szeroko rozumiane wskaźniki, będące w istocie niczym innym jak zwykłymi integer'ami -
	 * - liczbami (niezależnie od typu NA KTÓRY WSKAŹNIK WSKAZUJE). Więc wiemy już, że:
	 * 1. Każdy wskaźnik to zwykła liczba
	 * 2. Każdy wskaźnik wskazuje na określony typ danych.
	 * 
	 * Tak więc rozważmy definicję:
	 */
	char ch1;
	/**
	 * Jest to nic innego jak zmienna typu char, zajmująca na stosie programu sizeof(char) == 1 bajt (najprawdopodobniej)
	 * Idziemy dalej:
	 */
	char * ptr_ch1;
	/**
	 * Jest to zmienna typu (char *). Jest to liczba. Jest to wskaźnik na typ (char). 
	 * Ten wskaźnik, który jest normalną zmienną, znajduje się gdzieś normalnie, pod jakimś określonym adresem (możemy go dostać pisząc
	 * &ptr_ch1)), na stosie programu. Obecnie WARTOŚĆIĄ tej zmiennej są jakieś totalne śmieci. (To co znajdowało się wcześniej w tym miejscu
	 * w pamięci komputera, które system(?) w czasie wykonania programu przydzielił tej zmiennej)
	 * Ale możemy to zmienić:
	 */
	ptr_ch1 = &ch1;
	/**
	 * W tym momencie w zmiennej ptr_ch1 znajduje się ADRES pod którym w pamięci komputera znajduje się WARTOŚĆ zmiennej ch1. 
	 * Do tej pory raczej oczywiste ==> idziemy do wskaźników wielokrotnych:
	 */ 
	char ** pptr_ch1;
	/**
	 * TO JEST ZMIENNA - typu "wskaźnik na typ (char *)". Nie patrzyłbym na to  raczej jako "wskaźnik na wskaźnik do typu char"
	 * choć to jeszcze chyba poprawne, ale już w ogóle nie nazywałbym tego "wskaźnikiem na wskaźnik". Bo to jest jakiś bezsensowny łańcuszek
	 * niosący szczątkową ilość informacji. 
	 * Patrzyłbym na to tak: 
	 * pptr_ch1 jest wskaźnikiem (zmienną całkowitoliczbową) na tym (char *)
	 * Tak samo:
	 */
	char *** ppptr_ch1;
	/**
	 * Jest zmienną całkowitoliczbowa, wskaźnikiem na tym (char **)


	return 0;
}
