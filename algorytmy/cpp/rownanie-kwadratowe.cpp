// ROZWIAZYWANIE ROWNANIA KWADRATOWEGO Z WYKORZYSTANIEM FFUNKCJI SIGNUM 
#include <stdio.h>
#include <math.h>
#include <cstdlib>
using namespace std;
 
int signum(double * d)
{
	return (*d > 0) - (*d < 0);
}
 
void get_factors(double * a, double * b, double * c)
{
 
	printf("Podaj wspolczynniki rowania kwadratowego\npostaci ax^2 + bx + c = 0\n");
	printf("a != 0 !!\n");
	for (;;)
	{
		printf("Podaj a: ");
		scanf("%lf", a);
		printf("\nPodaj b: ");
		scanf("%lf", b);
		printf("\nPodaj b: ");
		scanf("%lf", c);
		if (*a != 0) break;
		else printf("a != 0\n\n");
	}
}
 
int main()
{
	// variables
	double *a = new double, *b = new double, *c = new double, *delta = new double;
	//-----------------------------------------
 
	get_factors(a, b, c);
	*delta = (((*b) * (*b)) - (4 * (*a) * (*c)));
 
	switch(signum(delta))
	{
		case 1:
		{
			printf("\nROWNANIE MA 2 PIERWIASTKI RZECZYWISTE:\n");
			printf("x1 = %0.4lf\n", ((-(*b) + sqrt(*delta))/(2* *a)));
			printf("x2 = %0.4lf\n", ((-(*b) - sqrt(*delta))/(2* *a)));
		}
		break;
 
		case 0:
		{
			printf("\nROWNANIE MA 1 PIERWIASTEK 2-KROTNY\n");
			printf("x = %0.4lf\n", ((-*b) / (2 * *a)));
		}
		break;
 
		case -1: 
		{
			printf("\nROWNANIE NIE MA PIERWIASTKOW RZECZYWISTYCH\nMA DWA PIERWIASTKI ZESPOLONE\n");
			printf("x1 = %0.4lf - %0.4lfi\n", (-(*b)/(2 * *a)), (fabs(sqrt(-*delta))/ (2 * *a)));
			printf("x1 = %0.4lf + %0.4lfi\n", (-(*b)/(2 * *a)), (fabs(sqrt(-*delta))/ (2 * *a)));
		}
		break;
 
		default:
		{
			printf("\nUps, cos poszlo nie tak\nChyba konczymy robote :)");
			exit(1);
		}
	}
 
	delete a; delete b; delete c; delete delta;
	return 0;
}
 
