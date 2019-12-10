#include <iostream>
#include <time.h>
using namespace std;

#define REP(i, a) for (int i = 0; i < a; ++i)
#define FORU(i, a, b) for (int i = a; i <= b; ++i)
#define FORD(i, a, b) for (int i = a; i >= b; --i)

const int N = 15;

template<class C> 
struct list
{
    C val = 0;
    // jeżeli tworzymy nowy element, to ma on wskazywać domyślnie na null
    // nie musimy tego potem robić ręcznie za każdym razem 
    list<C> * next = NULL;
};

// podajemy przez referencję żeby modyfikować rzeczywisty element!
template<class C>
void push_front(list<C> * &first, C value)
{
    // nie jestem pewien czy przy dodawaniu kolejnych elmentów nie zostają w pamięci zbędne wskaźniki
    list<C> * new_el = new list<C>;
    new_el->val = value;
    new_el->next = first;
    first = new_el;
}

template<class C>
void write_ls(list<C> * first, const string & s = "")
{
    cout << s << "\n";
    for (; first; first = first->next)
        cout << first->val << " ";
    
    cout << "\n";
}


int main()
{
    srand(time(NULL));
    // zawsze podstawić tutaj NULL'a!!!!!!
    list<int> * ls = NULL;
    REP(i, N)
    {
        cout << "dodaje: " << i << "\n";
        push_front(ls, i);
    }
    cout << "adres pierwszego: " << ls << "\n";
    write_ls(ls);
    cout << "adres pierwszego: " << ls << "\n";

    delete ls;
    return 0;
}
