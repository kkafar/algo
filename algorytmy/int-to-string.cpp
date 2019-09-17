#include <iostream>
#include <stack>
#include <string>
using namespace std;


// int to string function

string its(int n)
{
	string reversed, number;
	int lastDigit;

	while (n)
	{
		lastDigit = n % 10;
		n /= 10;
		reversed += static_cast<char>(lastDigit + 48);
		cout << reversed << "\n";
	}

	for (int i = reversed.length() - 1; i >= 0; --i)
	{
		number += reversed[i];
	}

	return number;
}

int main()
{
	int a; 

	cin >> a;
	cout << its(a) << "\n";
	return 0;
}
