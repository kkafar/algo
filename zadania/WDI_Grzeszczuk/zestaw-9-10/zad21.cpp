/*
    By K. Kafara
    11.01.2020
    Zestaw 9-10, zadanie 21
21. Dana jest lista, ktora zakończona jest cyklem. Napisać cunkcję, która zwraca liczbę elementów przed cyklem
Możliwe że zwraca o 1 za dużo, ale to już kosmetyka.
Rozwiązanie jest oparte na fakcie że odl. od miejsca spotkania do pierwszego elementu cyklu przystaje modulo
długość cyklu do odl. początku listy od miejsca spotkania (tych dwóch wskaźników). Można to dosyć łatwo wykazać.
*/

#include <iostream>
using namespace std;

template<typename T>
struct Element
{
    T val;
    Element * next;
    Element()
    {
        next = NULL;
    }
};
template<typename T>
struct List
{
    Element<T> * sentinel;
    Element<T> * tmp;
    List();
    ~List();
    Element<T> * push_front(const T & value);
    Element<T> * push_back(const T & value);
    void print_list();
    void clear();
    // does cycle exist
    bool dce();
    // non-cycle length
    int ncl();

};
template<typename T>
List<T>::List()
{
    sentinel = new Element<T>;
    sentinel->next = NULL;
    tmp = NULL;
}
template<typename T>
List<T>::~List()
{
    tmp = sentinel->next;
    delete sentinel;
    while (tmp != NULL)
    {
        sentinel = tmp;
        tmp = tmp->next;
        delete sentinel;
    }
    sentinel = NULL;
}
template<typename T>
Element<T> * List<T>::push_front(const T & value)
{
    tmp = new Element<T>;
    tmp->val = value;
    tmp->next = sentinel->next;
    sentinel->next = tmp;
    return tmp;
}
template<typename T>
Element<T> * List<T>::push_back(const T & value)
{
    tmp = new Element<T>;
    tmp->val = value;

    Element<T> * iter = sentinel;
    while (iter->next != NULL)
        iter = iter->next;

    iter->next = tmp;
    return tmp;
}
template<typename T>
void List<T>::print_list()
{
    tmp = sentinel->next;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << "\n";
}
template<typename T>
void List<T>::clear()
{
    tmp = sentinel->next;
    Element<T> * del;
    while (tmp != NULL)
    {
        del = tmp;
        tmp = tmp->next;
        delete del;
    }
    del = NULL;
    sentinel->next = NULL;
}
template<typename T>
int List<T>::ncl()
{
    /*
        Zakladamy ze w liscie jest cykl ==> nie jest pusta (zgodnie z trescia zadania zreszta
        ZNajdujemy miejsce spotkania wskaznika wolnego i szybkiego. Zliczamy liczbe krokow.
        ZWRACA O 1 ZA DUZO! (DLA CYCLE_LENG > 0)
    */
    Element<T> * slow = sentinel->next, * fast = slow;

    do
    {
        // wykonujemy najpierw po jednym kroku
        slow = slow->next;
        fast = fast->next; fast = fast->next;
        // niczego innego tutaj nie sprawdzamy, bo wiemy ze cykl ma byc
    } while (slow != fast);

    // w tym miejscu wiemy ze nasze wskaxniki sie spotkaly. Wyznaczamy odleglosc miejsca spotkania od poczatku listy.
    tmp = sentinel->next;
    // meeting point distance
    int mpd = 0; // nie jestem pewien czy nie powinno byc 1 tutaj
    while (tmp != slow)
    {
        tmp = tmp->next;
        ++mpd;
    }
    int cycle_leng = 0;
    do
    {
        slow = slow->next;
        ++cycle_leng;
    } while (slow != fast);
    int a = mpd / cycle_leng - 1;
    //cout << "a == " << a << "\n";
    tmp = sentinel->next;
    int ncleng = 0;
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < cycle_leng; ++j)
        {
            tmp = tmp->next;
            ++ncleng;
        }


    while (tmp != slow)
    {
        tmp = tmp->next;
        slow = slow->next;
        ++ncleng;
    }

    return ncleng;
}

int main()
{
    List<int> L;
    Element<int> * c = NULL, * last = NULL;
    for (int i = 0; i < 15; ++i)
    {
        if (i == 10) c = L.push_back(i);
        else if (i == 14) last = L.push_back(i);
        else L.push_back(i);
    }

    L.print_list();
    last->next = c;
    cout << L.ncl() << "\n";
    return 0;
}
