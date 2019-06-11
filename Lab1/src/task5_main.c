#include <stdio.h>
#include <math.h>

double f(double x);

int main()
{
	double x, y;

	printf("Enter X: "); scanf("%lf", &x);
	y = f(x);

	printf("x = %.4f\n", x);
	printf("y = %.4f\n", y);
	
	system("pause");
	return 0;
}
