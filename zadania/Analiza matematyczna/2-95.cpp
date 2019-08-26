#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double dl, *poz;
	int n, t;

	cin >> t;
	for (int j = 0; j < t; ++j)
	{
		cin >> dl >> n;

		poz = new double[n + 1];

		poz[0] = 0;
		poz[1] = dl / 2;

		for (int i = 2; i <= n; ++i)
		{
			poz[i] = (poz[i - 1] + poz[i - 2]) * 0.5;
		}

		cout << "Pozycja P_n (jako dlugosc odcinka |A P_n|): " << poz[n] << "\n";

		delete[] poz;
	}
	return 0;
}
