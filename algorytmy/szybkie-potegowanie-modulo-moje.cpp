#include <iostream>
using namespace std;

// dokładnie tak samo jak szybkie potęgowanie ale dokładamy jeszcze na wszystko modulo
long long power_mod(int a, int p, int q)
{
	long long result = 1; 
	int remainder = a; 

	while (p)
	{
		// jeżeli najmłodszy bit wykładnika jest niezerowy to dodajemy a^(waga aktualnie rozważanego bitu mod q)     
    // do rozkładu naszego rezultatu, a następnie bierzemy to mod q
		if (p & 1) result = (result * remainder) % q;

		remainder = (remainder * remainder) % q; 
		p >>= 1;
	}

	return result;
}

int main()
{
	int a, p, q, z; 

	cin >> z;

	for (int i = 0; i < z; ++i)
	{
		cin >> a >> p >> q; 
		cout << a << "^" << p << " mod " << q << " == " << power_mod(a, p, q) << "\n";
	}
	return 0; 
}
