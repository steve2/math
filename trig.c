#include <stdio.h>

/* mathematical pi */
#define PI 3.14159265358979
 
double to2pi (double);
double sine (double);
double cosine (double);

/* absolute value */
double absolute (double x) {
	if (x < 0.0) {
		return -x;
	} else {
		return x;
	}
}
 
int main () {
	char *str_sine[] = { 
		"sine(PI)", "sine(0)", "sine(PI/2)", "sine(PI/3)", "sine(PI/4)",
		"sine(PI/8)", "sine(2 * PI)", "sine(13 * PI)", "sine(12 * PI)",
		"sine(11 * PI)", "sine(11 * PI + PI / 2)", "sine(12 * PI + PI / 4)"
	};
	char *str_cosine[] = {
		"cosine(PI)", "cosine(0)", "cosine(PI/2)", "cosine(PI/3)", "cosine(PI/4)",
		"cosine(PI/8)", "cosine(2 * PI)", "cosine(13 * PI)", "cosine(12 * PI)",
		"cosine(11 * PI)", "cosine(11 * PI + PI / 2)", "cosine(12 * PI + PI / 4)"
	};
	double dbl_sine[] = {
		sine(PI), sine(0), sine(PI/2.0), sine(PI/3.0), sine(PI/4.0), sine(PI/8.0),
		sine(2.0 * PI), sine(13.0 * PI), sine(12.0 * PI), sine(11.0 * PI),
		sine(11.0 * PI + PI / 2.0), sine(12.0 * PI + PI / 4.0)
	};
	double dbl_cosine[] = {
		cosine(PI), cosine(0), cosine(PI/2.0), cosine(PI/3.0), cosine(PI/4.0),
		cosine(PI/8.0), cosine(2.0 * PI), cosine(13.0 * PI), cosine(12.0 * PI),
		cosine(11.0 * PI), cosine(11.0 * PI + PI / 2.0), cosine(12.0 * PI + PI / 4.0)
	};
	int length[] = { 12, 12 };
	int i;
	
	printf("\n----------------\n Sine Function:\n----------------\n");
	for (i = 0; i < length[0]; i++) {
		printf("%30s = %f\n", str_sine[i], dbl_sine[i]);
	}
	printf("\n----------------\n Cosine Function:\n----------------\n");
	for (i = 0; i < length[1]; i++) {
		printf("%30s = %f\n", str_cosine[i], dbl_cosine[i]);
	}
	return 0;
}

/**
 * sine (x)
 * 
 * @param double x, value of X to be used to calculate sine.
 *
 * Value given is converted into the range 0..2pi and calculated on an 
 * approximation of the sine function. Accuracy is 10^-12.
 */
double sine (double x) {
	double sum = 0.0, subj;
	int coef = 1;
	x = to2pi(x);
	subj = x;
	while (absolute(subj) > 0.000000000001) {
		sum += subj;
		subj *= (-1) * (x * x) / ((coef + 1) * (coef + 2));
		coef += 2;
	}
	return sum;
}

/**
 * cosine (x) 
 *
 * @param double x, value of X to be used to calculate cosine.
 *
 * Value given is converted into the range 0..2pi and calculated on an
 * approximation of the cosine function. Accuracy is 10^-12.
 */ 
double cosine (double x) {
	double sum = 0.0, subj;
	int coef = 0;
	x = to2pi(x);
	subj = 1;
	while (absolute(subj) > 0.000000000001) {
		sum += subj;
		subj *= (-1) * (x * x) / ((coef + 1) * (coef + 2));
		coef += 2;
	}
	return sum;
}

/**
 * to2pi (x)
 *
 * @param double x, value to transform into the new range restrictions.
 *
 * Transforms a given input X such that the returned value is equivalent for
 * use in TRIG functions. The new value is in the range (0..2pi]. Zero is 
 * converted into 2pi.
 */
double to2pi (double x) {
	return x - (2 * PI * ((int) (x / (2 * PI)) - 1));
}
