#include <iostream>

int main()
{
	int a, b;
	
	std::cin >> a >> b;
	
	std::cout << "(a, b) == (" << a << ", " << b << ")\n";

	a = a + b;
	b = a - b;
	a = a - b;

	std::cout << "(a, b) == (" << a << ", " << b << ")\n";

	return 0;
}
