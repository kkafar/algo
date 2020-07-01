#include <iostream>
#include <stack>
#include <string>
using namespace std;


int sti_horner(string & number)
{
	int result = number[0] - 48;
	for (int i = 1; i < number.length(); ++i)
	{
		result *= 10;
		result += (number[i] - 48);
	}

	return result;
}

int main()
{
	string number;

	cin >> number;

	cout << sti_horner(number) << "\n";

	return 0;
}
