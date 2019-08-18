// https://pl.spoj.com/problems/STOS/
#include <iostream>
using namespace std;


int main()
{
	int stack[10], top = -1;
	char ch;
	while(cin >> ch)
	{
		if (ch == '-')
		{
			if (top >= 0)
				cout << stack[top--] << "\n";
			

			else
				cout << ":(\n";
		}

		else if (ch == '+')
		{
			if (top < 9)
			{
				cin >> stack[++top];
				cout << ":)" << "\n";
			}

			else
			{
				cout << ":(\n";
			}
		}
	}



	return 0; 
}
