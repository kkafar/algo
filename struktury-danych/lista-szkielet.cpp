/*
  By K. Kafara
*/

#include <iostream>

using namespace std;

/* Reprezentacja listy za pomocą "łańcucha odsyłaczowego" */ 
template<typename type>
struct List
{
    struct Element
    {
        type val;
        Element * next = NULL;
    };

    // wskaźnik na pierwszy element listy 
    Element * first = NULL;
    // zmienna pomocnicza, do wstawiania, usuwania itd. 
    Element * tmp = NULL;

    /// =============================================================

    // metoda dodająca element o podanej wartośći  na początek listy
    /// =============================================================
    /*
        element dodawany jest zawsze na początek listy, nie przewiduję tu żadnych wyjątków, procedura jest następująca: 
        1. Rezerwujemy pamięć dla nowego elementu listy
        2. Ustawiamy wartośc  nowego elemenu na zadaną. 
        Skoro nowy element ma być pierwszy, to: 
        3. Ustawiamy wskaźnik na kolejny element dodawanego elementu na obecny pierwszy element w liście 
        4. Wskaźnik na pierwszy element przestawiamy na nowo dodany element
    */
    void insert(type value)
    {
        tmp = new Element;
        tmp->val = value;
        tmp->next = first;
        first = tmp;
    }
    /// =============================================================

    // metoda usuwająca pierwszy elementy z listy
    /// =============================================================
    /*
        Zwraca true jeżeli usuwanie zakończyło się sukcesem, false w przeciwnym przypadku (np. gdy lista jest pusta)
        Procedura jest następująca: 
        1. Sprawdzamy czy lista jest pusta:
            tak: 
                - zwracamy false 
            nie: 
                - przypisujemy adres pierwszego elementu do zmiennej pomocniczej 
                - adres pierwszego elemetntu ustawiamy na drugi element
                - zwalniamy pamięć zarezerwowaną na wyjściowy pierwszy element
                - zwracamy true
    */
    bool pop()
    {
        if (first == NULL) return false;

        tmp = first;
        first = first->next;
        delete tmp;
        return true;
    }
    /// =============================================================    

    /// =============================================================
    /* 
        Metoda wypisująca obecną zawartość listy.
    */
    /// =============================================================
    void print_list()
    {
        int nr = 1;
        for (register Element * iter = first; iter != NULL; iter = iter->next, ++nr)
            cout << nr << ": " << iter->val << "\n";
    }
};



int main()
{
    List<int> L;

    for (int i = 0; i < 15; ++i)
        L.insert(i);
    
    L.print_list();
    L.pop();
    L.print_list();
    L.pop();
    L.print_list();
    return 0;
}
