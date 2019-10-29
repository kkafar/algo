// TO DZIAŁA

#include <iostream>

using namespace std;

const int max_sys = 16;


int main()
{
    // a, b  to liczby dla których sprawdzamy czy w każdym systemie składają się z innyh cyfr
    int a, b, a_prim, b_prim;

    cin >> a >> b;

    bool cyfry_a[max_sys], cyfry_b[max_sys];
    for (int i = 0; i < max_sys; ++i)
    {
        cyfry_b[i] = false;
        cyfry_a[i] = false;
    }

    bool roznocyfrowe = true;
    
    int podstawa = 2;
    while (podstawa <= 16)
    {
        a_prim = a; b_prim = b; 
        while (a_prim > 0)
        {
            cyfry_a[a_prim % podstawa] = true;
            a_prim /= podstawa;
        }
        while (b_prim > 0)
        {
            cyfry_b[b_prim % podstawa] = true;
            b_prim /= podstawa;
        }

        for (int i = 0; i < max_sys; ++i)
            if (cyfry_a[i] == true && cyfry_b[i] == true)
             {
                roznocyfrowe = false;
             } 

        if (roznocyfrowe == false)
            break;

        else
        {
            ++podstawa;
            a_prim = a;
            b_prim = b;
        }
    }

    if (roznocyfrowe)
        cout << "TAK" << endl;

    else 
        cout << "NIE" << endl;
    return 0;
}
