#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
	double x, y;

	x = 2;
	y = pow(cos((3.0 / 8.0) * PI - x / 4.0), /*pow*/2.0) - pow(cos((11.0 / 8.0) * PI + x / 4.0), /*pow*/2.0);

	printf("x = %.4f\n", x);
	printf("y = %.4f\n", y);

	printf("Enter X: "); scanf("%lf", &x);
	y = pow(cos((3.0 / 8.0) * PI - x / 4.0), /*pow*/2.0) - pow(cos((11.0 / 8.0) * PI + x / 4.0), /*pow*/2.0);

	printf("x = %.4f\n", x);
	printf("y = %.4f\n", y);
	
	system("pause");
	return 0;
}
