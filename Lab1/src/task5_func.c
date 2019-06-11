#include <math.h>

#define PI 3.14159265359

double f(double x) {
	return pow(cos((3.0 / 8.0) * PI - x / 4.0), /*pow*/2.0) - pow(cos((11.0 / 8.0) * PI + x / 4.0), /*pow*/2.0);
}
