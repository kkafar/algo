#include <iostream>

#include "/home/kkafara/workspace/include/my-utility.h"
using namespace std;

void bit_swap(int & a, int & b)
{
	a = a ^ b;
	b = b ^ a;
	a = b ^ a;
}

int main()
{
	int a = 5, b = 7;
	cout << a << " " << b << "\n";
	bit_swap(a, b);
	cout << a << " " << b << "\n";
	
	return 0; 
}
