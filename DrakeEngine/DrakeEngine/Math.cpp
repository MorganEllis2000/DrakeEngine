#include "Math.h"

const double PI = 3.1415926535897932384626433832795028841971693993751058209;

namespace Math {

#pragma region General Functions
	float DegToRad(float d) {
		return (PI / 180) * d;
	}

	float RadToDeg(float r) {
		return (180 / PI) * r;
	}

	/*
	A method that will find better approximations to the roots with successive attemps

	x1 = x0 - (f(x0) / f'(x0))
	xn+1 = xn - (f(xn) / f'(xn))

	*/
	float sqrtNewton(float val, float estimate) {
		float error = abs(estimate * estimate - val);

		if (error <= 0.0001) {
			return estimate;
		}
		else {
			float newEstimate = (((val / estimate) + estimate) / 2);
			return sqrtNewton(val, newEstimate);
		}
	}

	float sqrt(float x) {
		if (x < 0) {
			return -1.0f;
		}
		else {
			return sqrtNewton(x, 1.0);
		}
	}

	/*
	Find the absolute value of our number 'a'
	*/
	float abs(float a) {
		if (a < 0) {
			return (-1 * a);
		}
		else {
			return a;
		}
	}
#pragma endregion

#pragma region Vector Math
	Vector3D add(Vector3D a, Vector3D b) {
		Vector3D sum = Vector3D();
		sum.x = a.x + b.x;
		sum.y = a.y + b.y;
		sum.z = a.z + b.z;

		return sum;
	}

	Vector3D subtract(Vector3D b, Vector3D a) {
		Vector3D diff = Vector3D();
		diff.x = b.x - a.x;
		diff.y = b.y - a.y;
		diff.z = b.z = a.z;

		return diff;
	}

	Vector3D multiply(Vector3D a, float c) {
		Vector3D mul = Vector3D();
		mul.x = a.x * c;
		mul.y = a.y * c;
		mul.z = a.z * c;

		return mul;
	}

	Vector3D divide(Vector3D a, float c) {
		Vector3D div = Vector3D();
		div.x = a.x / c;
		div.y = a.y / c;
		div.z = a.z / c;

		return div;
	}

	/*
	The dot product is used to find the angle between two set of vector coordinates

	A dot B = |A| * |B| * cos(theta)

	|A|, |B| = The magnitude of the vector

	The dot product can also be used to find the angle between points A and B

	cos(theta) = A * B / |A| * |B|

	*/
	float dot(Vector3D a, Vector3D b) {
		return a.x * b.x + a.y * b.y + a.z * b.z;
	}

	/*
	|A cross B | = |A| |B| sin(theta)

	A cross B = x(v1.y, v1.z, v2.y, v2.z) + y(v1.x, v1.z, v2.x, v2.z) + z(v1.x, v1.y, v2.x, v2.y)

	If we calculate the cross product using matrix notation we can take the determinant and the equation becomes

	v1 = v1.x * x + v1.y * y + v1.z * z
	v2 = v2.x * x + v2.y * y + v2.z * z
	crossProduct = v1 * v2

	 ______________________________
	|         |         |         |
	|    x    |    y    |    z    |		 ___________________	  ___________________	   ___________________
	| _______ | _______ |________ |		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|   v1.y  |   v1.z  |	 |  v1.x   |   v1.z  |	  |  v1.x   |   v1.y  |
	|  v1.x   |   v1.y  |   v1.z  | = x	|_________|_________| - y|_________|_________| + z|_________|_________|
	|_________|_________|_________|		|         |         |	 |         |         |	  |         |         |
	|         |         |         |		|   v2.y  |   v2.z  |	 |  v2.x   |   v2.z  |	  |  v2.x   |   v2.y  |
	|  v2.x   |   v2.y  |   v2.z  |		|_________|_________|	 |_________|_________|	  |_________|_________|
	|_________|_________|_________|

	crossProduct = x * ( (v1.y * v2.y) - (v1.z * v2.y) ) - y * ( (v1.z * v2.x) - (v1.x * v2.z) ) + z * * ( (v1.x * v2.y) - (v1.y * v2.x) )

	From this equation we can extrapolate the equations we need to perform on each axis in the crossproduct
	x = x * (v1.y * v2.y) - (v1.z * v2.y)
	y = -y * (v1.z * v2.x) - (v1.x * v2.z)
	z = z * (v1.x * v2.y) - (v1.y * v2.x)

	We already have a function that does this so we use this when calculating the final value

	*/
	Vector3D cross(Vector3D v1, Vector3D v2) {
		Vector3D crossProduct = Vector3D();
		crossProduct.x = det2x2(v1.y, v1.z, v2.y, v2.z);
		crossProduct.y = -1 * det2x2(v1.x, v1.z, v2.x, v2.z); // As seen above we need to subtract but we cant in this instance so we multiply by negative 1 to flip the sign
		crossProduct.z = det2x2(v1.x, v1.y, v2.x, v2.y);

		return crossProduct;
	}

	/*
	Finds the magnitude(length) of a vector

	|v| = sqrt(v.x^2 + v.y^2 + v.z^2)
	*/

	float magnitude(Vector3D v) {
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	/*
	Normalizing vectors allow use to get a value that will represent the direction of the vector but does not include its magnetude

	norm x = x / magnitude
	*/

	float normalizeX(Vector3D v, float m) {
		return v.x / m;
	}

	float normalizeY(Vector3D v, float m) {
		return v.y / m;
	}

	float normalizeZ(Vector3D v, float m) {
		return v.z / m;
	}

	/*
	distance = sqrt( (x - x2)^2 + (y - y2)^2 + (z - z2)^2) )
	*/
	float distance3D(Vector3D v1, Vector3D v2) {
		return sqrt(((v1.x - v2.x) * (v1.x - v2.x)) + ((v1.y - v2.y) * (v1.y - v2.y)) + ((v1.z - v2.z) * (v1.z - v2.z)));
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

	float det2x2(float a, float b, float c, float d) {
		return a * d - b * c;
	}

	float det3x3(float a, float b, float c, float d, float e, float f, float g, float h, float i) {
		float detA = a * ((e * i) - (f * h));
		float detB = b * ((d * i) - (f * g));
		float detC = c * ((d * h) - (e * g));
		return detA - detB + detC;
	}

	float det4x4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p) {
		float detA = a * ((f * k * p) - (f * l * o) - (g * j * p) + (g * l * n) + (h * j * o) - (h * k * n));
		float detB = b * ((e * k * p) - (e * l * o) - (g * i * p) + (g * l * m) + (h * i * o) - (h * k * m));
		float detC = c * ((e * j * p) - (e * l * n) - (f * i * p) + (f * l * m) + (h * i * n) - (h * j * m));
		float detD = d * ((e * j * o) - (e * k * n) - (f * i * o) + (f * k * m) + (g * i * n) - (g * j * m));
		return detA - detB + detC - detD;
	}
#pragma endregion


}
