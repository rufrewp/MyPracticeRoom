#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <locale.h>

_Bool isInArea(double x, double y)
{
	if ((x >= -1 && x <= 0) && (y >= -1 && y <= 0))
		return 1;
	else if ((x > 0 && y > 0 && sqrt(x * x + y * y) <= 1))
		return 1;
	else return 0;
}

double f(double x) {
	if (x <= 3) {
		return x * x - 3 * x + 9;
	}
	else {
		return 1 / (pow(x, 3.0) + 6);
	}
}


int main()
{
	setlocale(LC_ALL, "RUS");

	int selection;
	double x, y;

	while(true)
	{
		printf("1 - Первое задание\n");
		printf("2 - Второе задание\n");
		scanf("%d", &selection);
		
		switch(selection)
		{
			case 1:
			{
				printf("Введите координаты x и y:\n");
				printf("x = ");
				scanf_s("%lf", &x);
				printf("y = ");
				scanf_s("%lf", &y);
				printf("Результат: %o\n\n", isInArea(x, y));
				break;
			}
			case 2:
			{
				printf("Введите x: ");
				printf("x = ");
				scanf_s("%lf", &x);
				printf("Результат: %f\n\n", f(x));
				break;
			}
			default:
				return 1;
		}
	}

	return 0;
}

