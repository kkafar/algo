/*
    Algorytm generujący wszystkie podzbiory zbioru n-elementowego
    
*/

#include <iostream>
#define nl "\n"
using namespace std;
void fullfil_set(int * set, int size)
{
    for (int i = 0; i < size; ++i) 
    {
        (*set) = 0;
        ++set;
    }
}
void print_set(int * set, int size)
{
    for (int i = 0; i < size; ++i)
    {
        cout << *set << " ";
        ++set;
    }
    cout << nl;

}

void gen_subset(int * set, int size, int rek)
{
    //cout << "Wywolanie: size: " << size << "  rek: " << rek << nl;
    if (rek == size)
    {
        
        cout << "Wchodzi do petli: Wywolanie: size: " << size << "  rek: " << rek << nl;
        cout << "set: "; print_set(set,size);
        for (int i = 0; i < size; ++i)
        {
            if (set[i] == 1)
            {
                cout << i << " ";
            }
           
        }
        cout << nl;
    }
    else
    {
        set[rek] = 0;
        gen_subset(set, size, rek + 1);
        set[rek] = 1;
        gen_subset(set, size, rek + 1);
    }

}

int main()
{  
    int size = 4;
    int set[4];
    fullfil_set(set, size);
    print_set(set, size);
    gen_subset(set, size, 0);
    cout << nl;
    return 0;
}
