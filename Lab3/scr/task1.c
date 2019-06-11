#include "math.h"
#include <stdio.h>

double a(int i) 
{
	return pow(-1.0, (double)i) * ((pow(2.0, (double)i)) / (pow((double)i, (double)i + 1.0) + 1.0));
}

double summ(int n) {
	double s = 0.0;
	for (int i = 0; i < n; i++) {
		s += a(i);
	}
	return s;
}

double summ2(double eps) {
	double s = 0.0;
	int i = 0;
	double ai = 0.0;
	for (;;) {
		ai = a(i);
		s += ai;
		if (fabs(ai) > eps) {
			break;
		}
	}
	return s;
}

void print(int n, int k) {
	for (int i = 0; i < n; i++) {
		if (i % k == 0) continue;
		printf("%f\n", a(i));
	}
}

int findFirstElement(double eps) {
	int i = 0;
	for (;;) {
		if (fabs(a(i)) <= eps) {
			break;
		}
		++i;
	}

	return i;
}

int findFirstNegativeElement(double eps) {
	int i = 0;
	for (i = 0; fabs(a(i)) > eps && a(i) > 0; i++) {
		continue;
	}
	return i;
}

void task1() {
	printf("Enter n: ");
	int n;
	scanf_s("%d", &n);
	printf("%f\n\n", summ(n));
}

void task2() {
	printf("Enter eps: ");
	double eps;
	scanf_s("%lf", &eps);
	printf("%f\n\n", summ2(eps));
}

void task3() {
	printf("Enter n: ");
	int n;
	scanf_s("%d", &n);

	printf("Enter k: ");
	int k;
	scanf_s("%d", &k);

	print(n, k);
}

void task4() {
	printf("Enter eps: ");
	double eps;
	scanf_s("%lf", &eps);

	printf("%d\n\n", findFirstElement(eps));
}

void task5() {
	printf("Enter eps: ");
	double eps;
	scanf_s("%lf", &eps);

	printf("%d\n\n", findFirstNegativeElement(eps));
}

int main()
{
	int q = 0;
	do {
		printf("Enter 1-5 to run task, 6 to exit:");
		scanf_s("%d", &q);
		switch (q) {
		case 1:
			task1();
			break;
		case 2:
			task2();
			break;
		case 3:
			task3();
			break;
		case 4:
			task4();
			break;
		case 5:
			task5();
			break;
		case 6:
			return 0;
		}
	} while (q != 6);
	return 0;
}
