#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

double x, result;

void f(void) 
{
	result = pow(cos((3.0 / 8.0) * PI - x / 4.0), /*pow*/2.0) - pow(cos((11.0 / 8.0) * PI + x / 4.0), /*pow*/2.0);
}

int main()
{
	printf("Enter X: "); scanf("%lf", &x);
	f();

	printf("x = %.4f\n", x);
	printf("result = %.4f\n", result);
	
	system("pause");
	return 0;
}
