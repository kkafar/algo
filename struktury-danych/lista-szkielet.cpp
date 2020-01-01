#include <iostream>
#include <string>
using namespace std;

// wyciągamy definicję struktury (nie jestem pewien cyz tak to się akurat nazywa) żeby można było "widziały" ją 
// funkcje poza struct List
template<typename type>
struct Element
{
    type val;
    Element<type> * next = NULL;
};

/* Reprezentacja listy za pomocą "łańcucha odsyłaczowego" */ 
template<typename type>
struct List
{
public:

    // wskaźnik na pierwszy element listy 
    Element<type> * first = NULL;
    // zmienna pomocnicza, do wstawiania, usuwania itd. 
    Element<type> * tmp = NULL;

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
        tmp = new Element<type>;
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
    void print(const string & s = "")
    {
        int nr = 1;
        cout << s << "\n";
        for (register Element<type> * iter = first; iter != NULL; iter = iter->next, ++nr)
            cout << nr << " " << iter->val;
        cout << "\n";
    }
    /// =============================================================
};

