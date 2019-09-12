// konwertujemy liczbę z systemu dziesiętnego do systemu dwójkowego 


#include <iostream>
#include <stack>
using namespace std;

int main()
{
	// liczba w systemie dziesiętnym 
	int l;
	// stos do którego będziemy zbeirać kolejne bity liczby
	stack<int> s; 

	cin >> l;

	cout << l << " == ";
	// dopóki nasza liczba nie jest zerem;
	while (l)
	{
		if (l & 1) 	s.push(1);
		else 		s.push(0);

		l >>= 1;
	}

	// wyświetlamy zawartość stosu
	while (!s.empty())
	{
		cout << s.top(); 
		s.pop();
	}
	cout << endl;
	return 0; 
}

/// jak ja dawno niczego nie pisałem!
