#ifndef __MATH_H__
#define __MATH_H__

namespace Math
{
#pragma region General Functions
	double DegToRad(double d);

	double RadToDeg(double r);

	double sqrtNewton(double val, double estimate);
	double sqrt(double x);
	double quickInverseSqrt(float a_fvalue);

	double abs(double a);

	double pow(double a_base, double a_exponent);

	double modf(double a_value, double b_value);

	double factorial(double a_value);
#pragma endregion

#pragma region Trig Functions
	double sin(double a_value);
	double sinDeg(double a_value);
	double inverseSin(double a_value);

	double cos(double a_value);
	double cosDeg(double a_value);
	double inverseCos(double a_value);

	double tan(double a_value);
	double tanDeg(double a_value);
	double inverseTan(double a_value);

	double sec(double a_value);
	double inverseSec(double a_value);

	double cot(double a_value);
	double inverseCot(double a_fvalue);

	double csc(double a_value);
	double inverseCsc(double a_fvalue);
#pragma endregion

#pragma region Matrix Math
	double det2x2(double a, double b, double c, double d); // find the determinant for 2x2 matrix
	double det3x3(double a, double b, double c, double d, double e, double f, double g, double h, double i); // find the determinant for 2x2 matrix
	double det4x4(double a, double b, double c, double d, double e, double f, double g, double h, double i, double j, double k, double l, double m, double n, double o, double p);
#pragma endregion

#pragma region Mathematical Constants

	const double c_dPI			= 3.14159265358979323846;	 // pi
	const double c_dPI_2		= 1.57079632679489661923;	 // pi/2
	const double c_dPI_4		= 0.785398163397448309616;	 // pi/4
	const double c_d1_PI		= 0.318309886183790671538;	 // 1/pi
	const double c_d2_PI		= 0.636619772367581343076;   // 2/pi
	const double c_d2_SQRTPI	= 1.12837916709551257390;    // 2/sqrt(pi)
	const double c_dSQRT2		= 1.41421356237309504880;	 // sqrt(2)
	const double c_dSQRT1_2		= 0.707106781186547524401;	 // 1/sqrt(2)
	const double c_dE			= 2.71828182845904523536;    // e
	const double c_dLOG2E		= 1.44269504088896340736;	 // log_2(e)
	const double c_dLog10E		= 0.434294481903251827651;	 // log_10(e)
	const double c_dLN2			= 0.693147180559945309417;	 // log_e(2)
	const double c_dLN10		= 2.30258509299404568402;	 // log_e(10)

#pragma endregion
};

#endif // __MATH_H__