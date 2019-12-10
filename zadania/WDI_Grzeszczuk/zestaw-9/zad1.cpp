/* 
By: K. Kafara
1. Zaimplementuj zbiór mnogościowy liczb naturalnych korzystając ze
struktury listy.
- czy element należy do zbioru
- dodanie elementu do zbioru
- usunięcie elementu ze zbioru
*/

#include <iostream>
using namespace std;

#define REP(i, a) for (int i = 0; i < a; ++i)
#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)

struct set_N
{
    // struktura reprezentująca pojedynczy element zbioru
    struct element
    {
        unsigned int val;

        element * next = NULL;
    };

    // zmienne pomocnicze:
    // do śledzenia pierwszego elementu zbioru: 
    element * first = NULL;
    // do tworzenia nowych elementów, śledzenia (przy usuwaniu)itd…
    element * tmp = NULL;    

    // METODY
    //=================================

    // sprawdzanie czy element należy już do zbioru
    //=================================
    bool rep_val(const int & value)
    {
        // lecimy przez całą listę, jeżeli znaleźliśmy daną wartość to zwracamy false
        // w przeciwnym przypadku zwracamy true
        for (element * iter = first; iter; iter = iter->next)
            if (iter->val == value) return false;
        
        return true;
    }
    //=================================

    // dodawanie nowego elementu do zbioru
    //=================================
    bool push(const int & value)
    {
        if (value >= 0 && rep_val(value))
        {
            tmp = new element;
            tmp->val = value;
            tmp->next = first;
            first = tmp;

            return true;
        }
        else
            return false;
    }
    //=================================

    // usunięcie elementu ze zbioru
    //=================================
    bool del(const int & value)
    {
        // najpierw sprawdzamy czy nasz zbiór nie jest pusty
        if (first == NULL) return false;
        // w tym miejscu wiemy, że mamy co najmniej jeden element, ale żeby puścić trackera, potrzebujemy 
        // wiedzieć że mamy co najmniej 2 elementy
        if (first->next == NULL) 
        {
            if (first->val == value)        return true;
            else                            return false;
        }
        // wiemy już że mamy co najmniej 2 elementy
        register element * iter = first;
        // ważna kolejność sprawdzania w warunku pętli! Najpierw sprawdzamy czy nie wyszilśmy poza listę, a dopiero 
        // potem odwołujemy się do wartości ewentualnego elementu!
        while (iter != NULL && iter->val != value)
        {
            tmp = iter;
            iter = iter->next;
        }
        if (iter == NULL) return false;
        // pierwszy element musimy wyifować, żeby się potem do śmieci w tmp nie odwoływać
        if (iter == first) 
        {
            first = first->next;
            delete iter;
            return true;
        }
        // jeżeli nie wyszliśmy poza listę to znaczy, że udało nam się znaleźć szukaną wartość pod adresem (iter)
        // chcemy usunąć ten element, to ustawiamy (next) jego poprzednika na kolejny element po nim
        // zadziała nawet dla ostatniego elementu, bo prawidłowo ustawimy adres na NULL
        tmp->next = iter->next;
        iter->next = NULL;
        delete iter;

        return true;
    }
    //=================================

    // wypisywanie obecnej zawartości stosu
    //=================================
    void write_ls(const string & s = "")
    {
        cout << s << "\n";
        for (element * iter = first; iter; iter = iter->next)
            cout << iter->val << " ";
        cout << "\n";
    }
    //=================================


    //=================================

};

int main()
{
    set_N natural_set;
    REP(i, 20)
    {
        natural_set.push(i % 13);
    }
    natural_set.write_ls("NATURAL SET");
    natural_set.del(12);
    natural_set.write_ls("NATURAL SET \\{12}");
    return 0;
}
