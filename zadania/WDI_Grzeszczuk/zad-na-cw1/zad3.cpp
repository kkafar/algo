//3. Napisać program sprawdzający czy istnieje spójny podciąg ciągu Fibonacciego o
// zadanej sumie.
#include <iostream>
using namespace std;

// można się chyba obejść bez i, j ;
int main()
{
    int sij = 3, ss, i = 2, j = 3, l1 = 1, l2 = 1, p1 = 1, p2 = 2;

    cin >> ss;

    if (ss == 2)
        cout << "TAK\n";

    while (p2 < ss)
    {
        if (sij < ss)
        {
            ++j;
            p2 = p2 + p1; 
            p1 = p2 - p1; 
            sij += p2;
        }

        if (sij > ss)
        {
            ++i;
            l2 = l2 + l1;
            l1 = l2 - l1; 
            sij -= l1;
        }

        if (ss == sij)
        {
            cout << "TAK\n";
            return 0;
        }
    }

    // jeżeli wyszliśmy z while to taki podciąg nie istnieje
    cout << "NIE\n";

    return 0;
}
