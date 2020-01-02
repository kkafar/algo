/* 
    By K. Kafara
    Zestaw 9-10 zadanie 4
    4. Proszę napisać funkcję, która dla podanej listy odwraca kolejność jej
elementów.

Aby obrócić listę: tworzymy pomocniczą "kolejkę", przepisujemy do niej listę, a następnie 
iterując po wyjściowej liście i kolejce zmieniamy wartości elementom w liście

*/

#include <iostream>
#include <string>
using namespace std;

template<typename type>
struct Element
{
    type val;
    Element<type> * next = NULL;
};

template<typename type>
struct List
{
public:
    // wskaźnik na pierwszy element listy 
    Element<type> * first = NULL;
    // wskaźnik na ostatni element  listy 
    Element<type> * last = NULL; 
    // zmienna pomocnicza, do wstawiania, usuwania itd. 
    Element<type> * tmp = NULL;

    /// =============================================================

   
    /// =============================================================
    /*
        // metoda dodająca element o podanej wartośći  na początek listy
        element dodawany jest zawsze na początek listy, nie przewiduję tu żadnych wyjątków, procedura jest następująca: 
        1. Rezerwujemy pamięć dla nowego elementu listy
        2. Ustawiamy wartośc  nowego elemenu na zadaną. 
        Skoro nowy element ma być pierwszy, to: 
        3. Ustawiamy wskaźnik na kolejny element dodawanego elementu na obecny pierwszy element w liście 
        4. Wskaźnik na pierwszy element przestawiamy na nowo dodany element
    */
    void insert(const type & value)
    {
        tmp = new Element<type>;
        tmp->val = value;
        tmp->next = first;
        first = tmp;
        // jeżeli dodawany element jest pierwszym elementem, do jest za równo pierwszym jak i ostatnim
        if (first->next == NULL) last = first;
    }
    /// =============================================================

    /// =============================================================
    /*
        Metoda dodająca element na koniec listy
    */
    void append(const type & value)
    {
        // jeżeli lista jest pusta, to po prostu wstawiamy element
        if (first == NULL) 
        {
            this->insert(value); 
            return;
        }
        else if (first != NULL && first->next == NULL)
        {
            tmp = new Element<type>;
            tmp->val = value;
            first->next = tmp;
            last = tmp;
            return;
        }
        else
        {
            tmp = new Element<type>;
            tmp->val = value;
            last->next = tmp;
            last = tmp;
            return;
        }
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
        Metoda odwracająca kolejność elementów listy
    */
    void reverse()
    {
        List<type> queue;
        for (register Element<type> * iter = this->first; iter != NULL; iter = iter -> next)
            queue.insert(iter->val);

        for (register Element<type> * iter = this->first, * iter_q = queue.first;
         iter != NULL; iter = iter->next, iter_q = iter_q->next)
        {
            iter->val = iter_q->val;
        }
    }
    /// =============================================================  


    /// =============================================================
    /* 
        Metoda wypisująca obecną zawartość listy 
    */
    void print(const string & s = "")
    {
        //int nr = 1;
        cout << s << "\n";
        for (register Element<type> * iter = first; iter != NULL; iter = iter->next)
            cout << iter->val << " ";
        cout << "\n";
    }
    /// =============================================================

    /// =============================================================
    /*
        DESTRUKTOR
        Zwalnia całą zarezerwowana pamięć.
        Iteruje przez całą listę i zwalnia kolejne obszary pamięci.
    */
    ~List()
    {
        for (register Element<type> * iter = first; iter != NULL;)
        {
            tmp = iter;
            iter = iter->next;
            delete tmp;
        }
    }   
    /// =============================================================
};


int main()
{
    List<int> L, L2;
    for (int i = 0; i < 10; ++i)
    {
        L.insert(i);
        L2.append(i);
    }
    L.print("Before reversing");
    L.reverse();
    L.print("Reversed");
    L2.print("L2");
    L2.reverse();
    L2.print("L2 reversed");

    return 0;
}
