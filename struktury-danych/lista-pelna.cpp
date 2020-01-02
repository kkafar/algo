/* 
    By K. Kafara
    Zestaw 9-10 zadanie 3
    3. Proszę napisać funkcję scalającą dwie posortowane listy w jedną
posortowaną listę. Do funkcji należy przekazać wskazania na pierwsze
elementy obu list, funkcja powinna zwrócić wskazanie do scalonej listy.
- funkcja iteracyjna,
- funkcja rekurencyjna.


Do tego zadania potrzebujmey móc wstawiać element na początek listy - więc dodajemy do struktury listy 
pola do śledzenia adresu pierwszego element i przedostatniego elementu

*/

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


/// =============================================================
/*
    Funkcja realizująca zadanie 
    (Przyjmujemy sortowanie rosnące)
*/
template<typename T>
List<T> * merge_sorted_lists(Element<T> * first1, Element<T> * first2)
{
    // tworzymy listę, ale musimy to zrobić poprzez wskaźnik, bo jeżeli od razu utworzymy obiekt, to gdy 
    // funkcja zakończy swoje działanie pamięć zostanie zwolniona! A tak zostanie zlikwidowany tylko wskaźnik
    List<T> * merged_list = new List<T>;
    
    while (first1 != NULL && first2 != NULL)
    {
        if (first1->val < first2->val)
        {
            merged_list->append(first1->val);
            first1 = first1->next;
        }
        else 
        {
            merged_list->append(first2->val);
            first2 = first2->next;
        }
    }

    while (first1 != NULL)
    {
        merged_list->append(first1->val);
        first1 = first1->next;
    }
    while (first2 != NULL)
    {
        merged_list->append(first2->val);
        first2 = first2->next;
    }
    
    return merged_list; 
}
/// =============================================================

int main()
{
    List<int> L1, L2, * ml;

    for (int i = 10; i > 0; i -= 2)
    {
        L1.insert(i);
        L2.insert(i-1);
    }

    L1.print("L1");
    L2.print("L2");

    ml = merge_sorted_lists(L1.first, L2.first);

    ml->print("MERGED LIST");

    delete ml;

    for (int i = -1; i >= -5; --i)
        L1.insert(i);
    
    L1.print("NEW L1");

    ml = merge_sorted_lists(L1.first, L2.first);
    ml->print("MERGED LIST V2");

    List<int> L;
    for (int i = 0; i < 10; ++i)
    {
        L.append(i);
    }
    L.print();
    

    return 0;
}
