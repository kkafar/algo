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
	 * Jest zmienną całkowitoliczbowa, wskaźnikiem na typ (char **)
	 * Tak więc jeżeli zrobimy tak: 
	 */
	pptr_ch1 = &ptr_ch1;
	ppptr_ch1 = &pptr_ch1;
	/**
	 * To idąc "od zewnątrz" mamy:
	 * W zmiennej ppptr_ch1 ADRES pod którym znajduje się WARTOŚĆ zmiennej pptr_ch1. WARTOŚĆ zmiennej pptr_ch1 jest 
	 * ADRESEM pod którym znajduje się WARTOŚĆ zmiennej ptr_ch1. WARTOŚĆ zmiennej ptr_ch1 jest ADRESEM pod którym znajduje się
	 * WARTOŚĆ zmiennej typu char - ch1. 
	 * 
	 * Możemy przejść do tablic:
	 * Jeżeli chcemy mieć 10 zmiennych typu char w formie tablicy to mamy 2 podstawowe rozwiązania:
	 */
	char arr_ch1[10];
	/**
	 *  W takiej sytuacji, arr_ch1 jest typu (char *) --> czyli jest wskaźnikiem na typ char. 
	 * Co się stało: 
	 * Powiedzmy "program" wykonując się zarezerwował w tym momencie w pamięci komputera spójny obszar o długośći 10 * sizeof(char) bajtów. 
	 * arr_ch1 jest zmienną znajdującą się (w sumie sam nie wiem, czy wskaźnik na tablice znajduje się jakoś przy tablicy czy zupełnie losowo)
	 * gdzieś w pamieci komputera, nie ma znaczenia gdzie. WARTOSĆIĄ arr_ch1 jest ADRES pierwszego bajtu wcześniej  zarezerwowanego obszaru!!!
	 * 
	 * A no bo wcześniej zapomniałem: 
	 * ŻEBY DOSTAĆ SIĘ DO TEGO CO ZNAJDUJE SIĘ POD ADRESEM BĘDĄCYM WARTOŚCIĄ WSKAŹNIKA UŻYWAMY OPERATORA DEREFERENCJI.
	 * tj. jeżeli mamy:
	 * char * ptr = ch1; (ch1 zdefiniowane w linii 27) to: 
	 * wartością zmiennej ptr jest adres zmiennej ch1 ==> pod adresem zmiennej ch1 kryje się *ptr.
	 * 
	 * Wracajac: 2 ga opcja:
	 */
	char * arr_ch2 = (char *) malloc(10 * sizeof(char));
	/**
	 * Teraz sytuacja jest zdecydowanie inna. ZDEFINIOWALIŚMY zmienną typu char *, a zatem wskaźnik na typ char. Ta zmienna została utworzona
	 * na pewno gdzieś randomowo w pamięci przysługującej programowi. 
	 * Co zostanie wpisane do tej zmiennej? Kluczowe jest to co robi malloc. 
	 * Malloc ma głęboko w poważaniu na jaki typ danych chcesz zarezerwować miejsce w pamięci. Jego interesuje tylko ile tej pamięci chcesz. 
	 * dlatego przekazujesz mu w argumencie 10 * sizeof(char) żeby się zmieściło 10 zmiennych typu char. Malloc dogaduje się z systemem co i jak
	 * i w przypadku 1 wymiarowej tablicy rezerwuje spójny obszar pamięci o zadanym rozmiarze i zwraca adres pierwszego bajtu (w przypadku char)
	 * zarezerwowanego obszaru. Co istotne: typ zwracany przez malloc to (void *) -> wskaźnik na dowolny typ, 
	 * dlatego przed malloc należy go odpowiedno zrzutować. Dalej adres który zwrócił jest wpisywany do zmiennej arr_ch, która znajduje się
	 * niezależnie gdzieś tam w pamięci komputera. Teraz jeżeli chcemy poruszać się po tablicy to odwołujemy się do niej poprzez ten wskaźnik. 
	 */

	// oczywiśćie na koniec pamięć zarezerwowaną mallocem trzeba zwolnić - podając adres pierwszego elementu w zarezerwowanym obszarze. 
	free(arr_ch2);
	return 0;
}
