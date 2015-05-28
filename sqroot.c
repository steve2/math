#include <stdio.h>

double sqroot (double);
static double func (double, double);
static double deriv (double, double);

static double absolute (double x) {
	if (x < 0.0) {
		return -x;
	} else {
		return x;
	}
}

int main () {	
	double n[] = { 4.0, 2.0, 1.0, 64.0, 2.23, 3.1415, -1.0 };
	int length = 7, i;
	for (i = 0; i < length; i++) {
		printf("sqrt(%.5f) = %.5f\n", n[i], sqroot(n[i]));
	}
	return 0;
}

/**
 * Calculates the square root of a real number using Newton's method of root
 * finding. Finding the roots of the function f(x) = X^2 - N will yield the
 * square root of the number we're looking for.
 *
 * @param double n, function returns the square root of this value, given it
 *				abides by the conditions listed below.
 *
 * @conditions 
 *	• 'double n' must be positive, cannot find the square root of a negative
 *		number without introducing the 'i' value for sqroot(-1).
 */
double sqroot (double n) {
	double x0 = 1.0;
	if (n >= 0.0) {
		while (absolute(func(x0, n)) > 0.000000000001) {
			x0 = x0 - (func(x0, n) / deriv(x0, n));
		}
		return x0;
	} else {
		return -1.0;
	}
}

/**
 * 'func' and 'deriv' are the functions f(x) = X^2 - N and its derivative,
 * f(x) = 2X. Together they are used to calculate a root of 'func' with 
 * Newton's method.
 */
static double func (double x, double n) { return x * x - n; }
static double deriv (double x, double n) { return 2 * x; }
