#include <iostream>
#include <cmath>
using namespace std;
 
// co prawda miliony kopi, no ale... chyba żeby pyknąć za pomocą funkcji pow();
long long p(int a, int k)
{
	if (k == 0)			return 1; 
	if (k % 2 == 1)		return (a * pow(p(a, (k - 1) / 2), 2));
	else				return pow(p(a, k / 2), 2);
}
 
int main()
{
	int z, a, k, q; 
 
	cin >> z; 
 
	for (int j = 0; j < z; ++j)
	{
		cin >> a >> k >> q;
		cout << p(a, k) % q << endl;
	}
 
	return 0;
}
