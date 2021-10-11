#include "Math.h"

namespace Math {

#pragma region General Functions
	double DegToRad(double d) {
		return (c_dPI / 180) * d;
	}

	double RadToDeg(double r) {
		return (180 / c_dPI) * r;
	}

	/*
	A method that will find better approximations to the roots with successive attemps

	x1 = x0 - (f(x0) / f'(x0))
	xn+1 = xn - (f(xn) / f'(xn))

	*/
	double sqrtNewton(double val, double estimate) {
		double error = abs(estimate * estimate - val);

		if (error <= 0.00000001) {
			return estimate;
		}
		else {
			double newEstimate = (((val / estimate) + estimate) / 2);
			return sqrtNewton(val, newEstimate);
		}
	}
	double sqrt(double x) {
		if (x < 0) {
			return -1.0f;
		}
		else {
			return sqrtNewton(x, 1.0);
		}
	}
	/*
	This algorithm came from 1999s quate that uses the netwon method for square roots to estimate the root instead of doing 1/sqrt(x)

	  zzaz 
	*/
	double quickInverseSqrt(float a_fvalue) {
		const float x2 = a_fvalue * 0.5f; // half our initial value
		const float threehalfs = 1.5f;

		union {
			float f;
			unsigned int i;
		} conv = {conv.f = a_fvalue };
		conv.i = 0x5f3759df - (conv.i >> 1); // magic bitshifting that leads to the best estimation
		for (int j = 0; j < 50; ++j) {
			conv.f *= threehalfs - (x2 * conv.f * conv.f);
		}
		return conv.f;
	}

	/*
	Find the absolute value of our number 'a'
	*/
	double abs(double a) {
		if (a < 0) {
			return (-1 * a);
		}
		else {
			return a;
		}
	}

	double pow(double a_base, double a_exponent) {
		if (a_exponent == 0) {
			return 1;
		}
		double result = a_base;
		// Loop as many times as the power and just multiply itself power amount of times
		for (int i = 1; i < a_exponent; i++) {
			result = a_base * result;
		}
		return result;
	}

	double modf(double a_value, double b_value) {
		double mod;
		if (a_value < 0)
			mod = -a_value;
		else
			mod = a_value;
		if (b_value < 0)
			b_value = -b_value;

		while (mod >= b_value) {
			mod = mod - b_value;
		}

		if (a_value < 0) {
			return -mod;
		}

		return mod;
	}

	double factorial(double a_value) {
		if (a_value == 0) {
			return 1;
		}
		else {
			return a_value * (factorial(a_value - 1));
		}
	}
#pragma endregion

#pragma region Trig Functions
	/*
	sin x can be calculated using the Taylor Poly series
	sin(x) = x - x^3/3! + x^5/5! - x^7/7!
	*/
	double sin(double a_value) {
		double result = a_value;
		double coefficent = 3; // Increment this by 2 each loop
		for (int i = 0; i < 20; i++) { // Change 10 to go out to more/less terms
			double power = pow(a_value, coefficent);
			double frac = factorial(coefficent);

			// Switch between adding/subtracting
			if (i % 2 == 0) { // If the index of the loop is divided by 2, the index is even, so subtract
				result = result - (power / frac); // x - ((x^3)/(3!)) - ((x^5)/(5!))...
			}
			else {
				result = result + (power / frac); // x - ((x^3)/(3!)) + ((x^5)/(5!))...
			}
			coefficent = coefficent + 2;
		}
		return result;
	}
	double sinDeg(double a_value) {
		double rad = DegToRad(a_value);
		double s = sin(rad);
		return s;
	}
	/*
	arcsin(x) = ( (2n)! / ( 4^n * n!^2 * 2n+1 ) ) * x^2n+1 where n = 0
	*/
	double inverseSin(double a_value) {
		if (a_value == 1) {
			return -c_dPI_2;
		}
		if (a_value == 0) {
			return 0;
		}
		if (a_value == -1) {
			return c_dPI_2;
		}
		if (a_value > 1 || a_value < -1) {
			throw "inverseSin can only be calculated with numbers >= -1 and <= 1";
		}

		double result = a_value;
		for (double n = 1; n < 70; n++) {
			double power = factorial(2 * n);
			double frac = pow(4, n) * pow(factorial(n), 2) * (2 * n + 1);
			result = result + ((power / frac) * (pow(a_value, (2 * n + 1))));
		}
		return result;
	}

	/*
	cos x can be calculated using the Taylor Poly series
	cos(x) = x - x^2/2! + x^4/4! - x^6/6!
	*/
	double cos(double a_value) {
		double result = 1.f;
		double coefficent = 2; // Increment this by 2 each loop
		for (int i = 0; i < 20; i++) {
			double power = pow(a_value, coefficent);
			double frac = factorial(coefficent);

			// Switch between adding/subtracting
			if (i % 2 == 0) { // If the index of the loop is divided by 2, the index is even, so subtract
				result = result - (power / frac); // x - ((x^3)/(3!)) - ((x^5)/(5!))...
			}
			else {
				result = result + (power / frac); // x - ((x^3)/(3!)) + ((x^5)/(5!))...
			}
			coefficent = coefficent + 2;
		}
		return result;
	}
	double cosDeg(double a_value) {
		double rad = DegToRad(a_value);
		double c = cos(rad);
		return c;
	}
	/*
	arccos(x) = PI/2 - arcsin(x)
	*/
	double inverseCos(double a_value) {
		if (a_value == 1) {
			return 0;
		}
		if (a_value == 0) {
			return c_dPI_2;
		}
		if (a_value == -1) {
			return c_dPI;
		}
		return c_dPI_2 - inverseSin(a_value);
	}

	/*
	Tan(x) = sin(x)/ cos(x)
	*/
	double tan(double a_value) {
		if (a_value > c_dPI_2 || a_value < -c_dPI_2) {
			throw "inverseSin can only be calculated with numbers >= -PI/2 and <= PI/2";
		}
		return sin(a_value) / cos(a_value);
	}
	double tanDeg(double a_value) {
		double rad = DegToRad(a_value);
		double t = tan(rad);
		return t;
	}
	/*
	arctan(x) = ( (2n)! / (2n+1) ) * x^2n+1
	*/
	double inverseTan(double a_value) {
		double result = a_value;
		double coefficent = 3; 
		for (int i = 2; i < 10; i++) {
			double power = pow(a_value, coefficent);

			
			if (i % 2 == 0) { 
				result = result - (power / coefficent); 
			}
			else {
				result = result + (power / coefficent); 
			}
			coefficent = coefficent + 2;
		}
		return result;
	}

	/*
	sec = 1 / cos(x)
	*/
	double sec(double a_value) {
		return 1 / cos(a_value);
	}
	/*
	arcsec(x) = PI/2 - ( (2n)! / (2^2n * n!^2 * 2n+1 * x^2n+1) )
	*/
	double inverseSec(double a_fvalue) {
		double result = 0;
		for (double n = 0; n < 70; n++) {
			double num = factorial(2 * n);
			double den = pow(2, (2 * n)) * pow(factorial(n), 2) * (2 * n + 1) * pow(a_fvalue, 2 * n + 1);

			result = result + (num / den);

		}
		return c_dPI_2 - result;
	}

	/*
	cot = cos(x) / sin(x)
	*/
	double cot(double a_value) {
		return cos(a_value) / sin(a_value);
	}
	/*
	arccot(x) = PI/2 - arctan(x)
	*/
	double inverseCot(double a_fvalue) {
		return c_dPI_2 - inverseTan(a_fvalue);
	}

	/*
	csc = 1 / sin(x)
	*/
	double csc(double a_value) {
		return 1 / sin(a_value);
	}
	/*
	arccsc(x) = (2n)! / (2^2n * n!^2 * 2n+1 * x^2n+1)
	*/
	double inverseCsc(double a_fvalue) {
		double result = 0;
		for (double n = 0; n < 70; n++) {
			double num = factorial(2 * n);
			double den = pow(2, (2 * n)) * pow(factorial(n), 2) * (2 * n + 1) * pow(a_fvalue, 2 * n + 1);

			result = result + (num / den);

		}
		return result;
	}
#pragma endregion

#pragma region Matrix Math
	/*
	Find the determinant of the a square matrix, doing so gives a scalar value that allows
	characterisation of some properties of the matrix and the linear map of the matrix.

	For 2x2 matrixes:
	 ___________________
	|         |         |
	|    A    |    B    |
	| _______ | _______ | = AD - BC
	|         |         |
	|    C    |    D    |
	|_________|_________|

	 ___________________
	|         |         |
	|    3    |    7    |
	| _______ | _______ | = (3 * -4) - (7 * 1) = -12 - 7 = -19
	|         |         |
	|    1    |   -4    |
	|_________|_________|


	For 3x3 matrixes:
	 ______________________________
	|         |         |         |
	|    A    |    B    |    C    |		 ___________________	  ___________________	   ___________________
	| _______ | _______ |________ |		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|    E    |    F    |	 |    D    |    F    |	  |    D    |    E    |
	|    D    |    E    |    F    | = A	| _______ | _______ | - B| _______ | _______ | + C| _______ | _______ | = A(EI - FH) - B(DI - FG) + C(DH - EG)
	|_________|_________|_________|		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|    H    |    I    |	 |    G    |    I    |	  |    G    |    H    |
	|    G    |    H    |    I    |		|_________|_________|	 |_________|_________|	  |_________|_________|
	|_________|_________|_________|

	 ______________________________
	|         |         |         |
	|    3    |   -4    |   -5    |		 ___________________	  ___________________	   ___________________
	| _______ | _______ |________ |		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|   -7    |    8    |	 |    7    |    8    |	  |    7    |   -7    |
	|    7    |   -7    |    8    | = A	| _______ | _______ | - B| _______ | _______ | + C| _______ | _______ | =
	|_________|_________|_________|		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|   -7    |   -8    |	 |    5    |   -8    |	  |    5    |   -7    |
	|    5    |   -7    |   -8    |		|_________|_________|	 |_________|_________|	  |_________|_________|
	|_________|_________|_________|

	= 3 * ((-7 * -8) - (8 * -7)) - -4 * ((7 * -8) - (8 * 5)) + -5 * ((7 * -7) - (-7 * 5))
	= (3 * 112) - (-4 * -96) + (-5 * -14)
	= 336 - 384 + 70
	= 22

	For 4x4 matrixes:
	 ________________________________________
	|         |         |         |         |    ________  _________ _________		 ________  _________ _________	     ________  _________ _________       ________  ________  _________
	|    A    |    B    |    C    |    D    |   |         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	| _______ | _______ |________ |________ |	|    F    |    G    |    H    |		|    E    |    G    |    H    |		|    E    |    F    |    H    |		|    E    |    F    |    G    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    E    |    F    |    G    |    H    |  	|         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	|_________|_________|_________|_________|= A|    J    |    K    |    L    |	- B	|    I    |    K    |    L    | + C	|    I    |    J    |    L    | - D	|    I    |    J    |    K    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    I    |    J    |    K    |    L    |	|         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	|_________|_________|_________|_________|	|    N    |    O    |    P    |		|    M    |    O    |    P    |		|    M    |    N    |    P    |		|    M    |    N    |    O    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    M    |    N    |    O    |    P    |
	|_________|_________|_________|_________|

	= A(FKP - FLO - GJP + GLN + HJO - HKN) - B(EKP - ELO - GIP + GLM + HIO - HKM) + C(EJP - ELN - FIP + FLM + HIN - HJM) + D(EJO - EKN - FIO + FKM + GIN - GJM)

	 ________________________________________
	|         |         |         |         |    ________  _________ _________		 ________  _________ _________	     ________  _________ _________       ________  ________  _________
	|    5    |    7    |    9    |    4    |   |         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	| _______ | _______ |________ |________ |	|    5    |    8    |    4    |		|    3    |    8    |    4    |		|    3    |    5    |    4    |		|    3    |    5    |    8    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    3    |    5    |    8    |    4    |  	|         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	|_________|_________|_________|_________|= 5|    3    |    8    |    4    |	- 7	|    1    |    8    |    4    | + 9	|    1    |    3    |    4    | - 4	|    1    |    3    |    8    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    1    |    3    |    8    |    4    |	|         |         |         |		|         |         |         |		|         |         |         |		|         |         |         |
	|_________|_________|_________|_________|	|    7    |    1    |    3    |		|    3    |    1    |    3    |		|    3    |    7    |    3    |		|    3    |    7    |    1    |
	|         |         |         |         |	|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|		|_________|_________|_________|
	|    3    |    7    |    1    |    3    |
	|_________|_________|_________|_________|


	= 5 * ( (5*8*3) - (5*4*1) - (8*3*3) + (8*4*7) + (4*3*1) - (4*8*7) ) -
	 -7 * ( (3*8*3) - (3*4*1) - (8*1*3) + (8*4*3) + (4*1*1) - (4*8*3) ) +
	  9 * ( (3*3*3) - (3*4*7) - (5*1*3) + (5*4*3) + (4*1*7) - (4*3*3) ) -
	 -4 * ( (3*3*1) - (3*8*7) - (5*1*1) + (5*8*3) + (8*1*7) - (8*3*3) )

	= 5 * ( 120 - 20 - 72 + 224 + 12 - 224 ) -
	 -7 * ( 72 - 12 - 24 + 96 + 4 - 96) +
	  9 * ( 27 - 84 - 15 + 60 + 28 - 36) -
	 -4 * ( 9 - 168 - 5 + 120 + 56 - 72)

	= -20


	*/

	double det2x2(double a, double b, double c, double d) {
		return a * d - b * c;
	}

	double det3x3(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
		double detA = a * ((e * i) - (f * h));
		double detB = b * ((d * i) - (f * g));
		double detC = c * ((d * h) - (e * g));
		return detA - detB + detC;
	}

	double det4x4(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double m, double n, double o, double p) {
		double detA = a * ((f * k * p) - (f * l * o) - (g * j * p) + (g * l * n) + (h * j * o) - (h * k * n));
		double detB = b * ((e * k * p) - (e * l * o) - (g * i * p) + (g * l * m) + (h * i * o) - (h * k * m));
		double detC = c * ((e * j * p) - (e * l * n) - (f * i * p) + (f * l * m) + (h * i * n) - (h * j * m));
		double detD = d * ((e * j * o) - (e * k * n) - (f * i * o) + (f * k * m) + (g * i * n) - (g * j * m));
		return detA - detB + detC - detD;
	}
#pragma endregion

}
